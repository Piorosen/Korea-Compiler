int Int_Data(char *Name, Var Var){
	int len = strlen(Name);
	int i = 0;
	bool check;
	for (;i > len; i++){
		if (*(Name+i) >= 48 && *(Name+i) <= 57){
			continue;
		}else{
			check = false;
		}
	}
	check = Var.List(Name, Var);
	if (check == false){
		return atoi(Name);
	}else{
		int Num = 0;
		for(;Num < Var.Int_Count - 1;Num++){
			if ((strcmp(Name, *(Var.Int_Var_Name+Num)) == 0)  && ((Var.Int_Count - 1) > Num)){
				return Var.Int_Var_Data[Num];
			}
			else continue; 
		}for (Num=0;Num < Var.Char_Count - 1;Num++){
			if ((strcmp(Name, *(Var.Char_Var_Name+Num)) == 0) && ((Var.Char_Count - 1) > Num)){
				return atoi(Var.Char_Var_Data[Num]);
			}
			else continue;
		}
	}
	return 0;
}

char *Quotation_Marks(char *Name, char s = '\"', bool Error = false){
	int i = 0;
	int k = strlen(Name);
	char *temp = (char *)calloc(sizeof(char), k);
	int tmp = 0;
	if (*(Name+0) != s){
		Error_Solve("코드 에러", "앞뒤에 위치하지 않습니다.", 0);
	}
	for (;i < k - 1; i++){
		if(*(Name+i) == s){
			tmp++;
			continue;
		}else{
			sprintf(temp, "%s%c", temp, *(Name+i));
		}
	}
	if (tmp%2 == 0)
	return temp;
	else Error_Solve("코드 에러", "갯수가 짝수가 아닌 홀수입니다.", 0);return 0;
}

char *Next_Sentence(char *Name, char s = '#', bool New_Mode = false){
	static int Check;
	int F_Check = 0;
	int i = 0;
	int k = strlen(Name);
	char *temp = (char *)calloc(sizeof(char), k+1);
	Check+=1;
	if (New_Mode){
		Check = 0;
		if (*(Name+0) == s){
			Check+=1;
			i+=2;
			for(;;i++){
				if (*(Name+i) == '\0'){
					Check=0;
					return temp;
				}else if (*(Name+i+1) == s){
					return temp;
				}else{
					sprintf(temp, "%s%c", temp, *(Name+i));
				}
			}
		}else{
			for(;;i++){
				if (*(Name+i) == '\0'){
					Check=0;
					return temp;
				}else if (*(Name+i+1) == s){
					return temp;
				}else{
					sprintf(temp, "%s%c", temp, *(Name+i));
				}
			}
		}
	}
	for(;;i++){
		if (*(Name+i) == s)F_Check+=1;
		if (*(Name+i) == s && Check == F_Check){
			for(;;i++){
				if (*(Name+i+2) == '\0'){
					Check=0;
					return temp;
				}else if (*(Name+i+3) == s){
					return temp;
				}else{
					sprintf(temp, "%s%c", temp, *(Name+i+2));
				}
			}
		}else{
			continue;
		}
	}
}

int Mstrlen(char *len){
	int temp = 0;
	while(*len){
		len++;
		temp++;
	}
	return (temp + 1);
}

bool Num_Check(char *Num){
	int len = strlen(Num);
	int i = 0;
	for(;i < len; i++){
		if (*(Num+i) < 57 && *(Num+i) > 48){
			continue;
		}else{
			return false;
		}
	}
	return true;
}
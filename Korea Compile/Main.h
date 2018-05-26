void Error_Solve(char *Cause, char *Solve,int Error_Line){
	cls();
	printf("\n원인 구간 : %s\n\n해결 방법 : %s\n\n오류난 곳 : %d 번째로 실행된 코드", Cause, Solve, Error_Line);
	getch();
	exit(1);
}

bool Var::Name_Check(char *Name){
	int i = 0, len;
	len = strlen(Name);
	for (;len > i; i++){
		if ((Name[i] >= 65 && Name[i] <= 122) || (Name[i] <= 48 && Name[i] <= 57)){
			continue;
		}else if ((i == 0) && (Name[i] >= 65 && Name[i] <= 122)){
			continue;
		}else{
			return false;
		}
	}
	return true;
}

bool Char_Check(char *Name, Var Var){
	int Num = 0;
	for (;Num < Var.Char_Count - 1;Num++){
		if ((strcmp(Name, *(Var.Char_Var_Name+Num)) == 0) && ((Var.Char_Count - 1) > Num))return true;
		else continue;
	}return  false;
}

bool Int_Check(char *Name, Var Var){
	int Num = 0;
	for(;Num < Var.Int_Count - 1;Num++){
		if ((strcmp(Name, *(Var.Int_Var_Name+Num)) == 0)  && ((Var.Int_Count - 1) > Num))return true;
		else continue;
	}return  false;
}

bool File_Check(char *Name, Var Var){
	int Num = 0;
	for (;Num < Var.File_Count - 1;Num++){
		if ((strcmp(Name, *(Var.File_Var_Name+Num)) == 0) && ((Var.File_Count - 1) > Num))return true;
		else continue;
	}return  false;
}

bool Var::List(char *Name, Var Var){
	int Num = 0;
	for(;Num < Var.Int_Count - 1;Num++){
		if ((strcmp(Name, *(Var.Int_Var_Name+Num)) == 0)  && ((Var.Int_Count - 1) >= Num))return true;
		else continue;
	}for (Num=0;Num < Var.Char_Count - 1;Num++){
		if ((strcmp(Name, *(Var.Char_Var_Name+Num)) == 0) && ((Var.Char_Count - 1) >= Num))return true;
		else continue;
	}for (Num=0;Num < Var.File_Count - 1;Num++){
		if ((strcmp(Name, *(Var.File_Var_Name+Num)) == 0) && ((Var.File_Count - 1) >= Num))return true;
		else continue;
	}
	return false;

}
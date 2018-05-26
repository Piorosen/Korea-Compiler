// 통합출력
void print(char OP[256], int Error_Code_Line){
	int i=1;
	char Error[282];
	int Count = 0;
	int Var_Count[3] = {0,};

	if ( OP[0] != '\"'){sprintf(Error, "출력 %s", OP);Error_Solve(Error, "첫 글자 의 시작부분을 알수가 없습니다.", Error_Code_Line);}

	for(;i < strlen(OP)-1; i++){
		if (OP[i] == '\\' && (OP[i+1] == 'e' || OP[i+1] == 'E')){
			printf("\n");
			i+=1;
		}else if ( OP[i] == '%' && ( OP[i+1] == 'd' || OP[i+1] == 'D' )){
		
		}else if ( OP[i] == '\"'){


		}else{
			printf("%c", OP[i]);
		}
	}
	return;
}

// 문자출력
void printVX(char *OP, int Error_Code_Line){
	int i=1;
	char *Error = new char[strlen(OP) + strlen("문자출력 ") + 1];
	int k = Mstrlen(OP);
	if ( OP[0] != '\"'){sprintf(Error, "문자출력 %s", OP);Error_Solve(Error, "첫 글자 의 시작부분을 알수가 없습니다.", Error_Code_Line);}
	delete []Error;

	for(;i < k; i++){
		if (OP[i] == '\\'){
			switch (OP[i + 1]){
			case '\"':
				printf("\"");
				i++;
				break;
			case 'n' :
				printf("\n");
				i++;
				break;
			case '\\':
				printf("\\");
				i++;
				break;
			default  :
				break;
			}
		}else if (OP[i] == '\"'){
			break;
		}else{
			printf("%c", OP[i]);
		}
	}
	return;
}

// 변수출력 
void printVO(char *OP, int Error_Code_Line, Var Var){
	int len = 0;
	bool List = Var.List(OP, Var);

	char Error[256] = {0,};
	sprintf(Error, "%s %s", "변수출력", OP);
	if (List == false){
		Error_Solve(Error, "변수 이름이 잘못 입력되었습니다.", Error_Code_Line);
	}
	for(;;len++){
		if (Var.Int_Count != 1){
			if ((strcmp(OP, Var.Int_Var_Name[len]) == 0)  && (Var.Int_Count - 1) > len ){
				printf("%d", *(Var.Int_Var_Data+len));return;
			}
		}if (Var.Char_Count != 1){
			if ((strcmp(OP, Var.Char_Var_Name[len]) == 0) && (Var.Char_Count - 1) > len){
				printf("%s", *(Var.Char_Var_Data+len));
				return;
			}
		}/*if ((strcmp(OP, Var.Float_Var_Name[len]) == 0) && (Var.Float_Count - 1) > len){
			return true;
		}*/
	}
	return;
}

// 연산 하는곳

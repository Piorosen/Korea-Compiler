void gotoxy(char *x, char *y, int Error_Code_Line, Var Var){
	int Check[2];
	bool check[2];
	char temp[256] = {0,};
	int ix = 0, iy = 0;
	check[0] = Num_Check(x);
	check[1] = Num_Check(y);
	if (check[0] == true){
		ix = atoi(x);
	}if (check[1] == true){
		iy = atoi(y);
	}
	Check[0] = Var.List(x, Var);
	Check[1] = Var.List(y, Var);
	if (Check[0] > 0){
		ix = Int_Data(x, Var);
	}if (Check[1] > 0){
		iy = Int_Data(y, Var);
	}
	if (ix < 0 || iy < 0){
		sprintf(temp, "%s %s %s", "문자 위치변경", x, y);
		Error_Solve(temp, "문자위치변경을 실행할수가 없습니다.", Error_Code_Line);
	}
    COORD CUR;
	CUR.X = ix;
	CUR.Y = iy;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), CUR);
}

bool IF(char Input[256],int Error_Code_Line,FILE *DataRead, Var Var){
	bool check = true;
	bool Check[2];
	bool OK[2] = {false,};

	int Data[2] = {0,};
	char *Data1;
	char *Data2;
	char *Data3;
	char *null = NULL;
	Data1 = strtok_s(Input, "|", &null);
	Data2 = strtok_s(NULL, "|", &null);
	Data3 = strtok_s(NULL, "|", &null);
	Check[0] = Var.List(Data1, Var);
	Check[1] = Var.List(Data3, Var);
	if (Check[0] == false){
		if(*(Data1+0) == '\''){
			Data[0] = (int)(*(Data1+1));
			OK[0] = true;
			goto IF_CHECK1;
		}else{
			int i = 0;
			for(;isdigit(*(Data1+i)); i++){{
				if (!isdigit(*(Data1+i))){
					check = false;
				}
			}
		}
		}if (check){
			Data[0] = atoi(Data1);
			OK[0] = true;
			goto IF_CHECK1;
		}else{
			strcpy(Input, "만약 ");
			Error_Solve(Input, "여기서 이러시면 안되요.", Error_Code_Line);
		}
	}else{
		Data[0] = Int_Data(Data1, Var);
	}
IF_CHECK1:
	check = true;
	if (Check[1] == false){
		if(*(Data3+0) == '\''){
			Data[1] = (int)(*(Data3+1));
			OK[1] = true;
			goto IF_CHECK2;
		}else{
			int i = 0;
			for(;isdigit(*(Data3+i)); i++){{
				if (!isdigit(*(Data3+i))){
					check = false;
				}
			}
		}
		}if (check){
		Data[1] = atoi(Data3);
			OK[1] = true;
			goto IF_CHECK2;
		}else{
			strcpy(Input, "만약 ");
			Error_Solve(Input, "여기서 이러시면 안되요.", Error_Code_Line);
		}
	}else{
		Data[0] = Int_Data(Data1, Var);
	}
IF_CHECK2:
	if (*(Data2 + 0) == '='){
		if (Data[0] == Data[1]){
			fscanf(DataRead, "%s ", Input);
			return true;
		}else{
			return false;
		}
	}else if (*(Data2 + 0) == '>'){
		if (Data[0] > Data[1]){
			fscanf(DataRead, "%s ", Input);
			return true;
		}else{
			return false;
		}
	}else if (*(Data2 + 0) == '<'){
		if (Data[0] < Data[1]){
			fscanf(DataRead, "%s ", Input);
			return true;
		}else{
			return false;
		}
	}else{
		sprintf(Input, "만약 %s %s %s", Data1, Data2, Data3);
		Error_Solve(Input, "이러한 문법은 허용되지 않습니다.", Error_Code_Line);
		return false;
	}
}
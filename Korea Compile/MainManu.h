void MainFunc(int Dat_Check){
	system("cls");
	switch (Dat_Check){
	case 0 :
		break;
	case 1 :
	case 3 :
		printf("속성오류 입니다.");
		getch();
		exit(1);
		break;
	case 2 :
		MicroTest();
	default :
		printf("속성 오류");
		getch();
		exit(1);
		break;
	}
	
	int ch;
	printf("\t모드 선택 해주세요.\n\n");
	printf("1. 에러 검출 - 문법만 처리합니다.\n\n");
	printf("2. 정밀 검출 - 모든 에러를 처리합니다. 하지만 에러 검출속도가 느립니다.\n\n");
	printf("3. 파일 구동 - 에러가 걸리면 무시하고 계속합니다.\n\n");
	printf("4. 속성 변경 - 속성을 변경을합니다.\n\n");
	printf("ESC. 종료 하기 - 프로그램을 종료를 합니다.\n\n\n\n");
	printf("추신 - 번호만 눌리시면은 됩니다. : ");
	for (;;){
		ch = getch();
		switch ( ch ){
		case '1' :
			printf("미구현 입니다.");
			
			break;
		case '2' :
			MicroTest();
			break;
		case '3' :
			printf("미구현 입니다.");
			break;
		case '4' :
			Detail_Change_Mode(Dat_Check); 
			break;
		case 27 :
			exit(1);
			break;
		default :
			continue;
			break;
		}
	}
}

int Dat(){
	FILE *Dat = fopen("KBL.Dat", "r+");
	char profile[PROFILE_FIRST][26];

	if (Dat == 0 ){
		Dat = fopen("KBL.Dat", "w+");
		fprintf(Dat, "MainManuConnect = 0");
		fclose(Dat);
	}
	Dat = fopen("KBL.Dat", "r+");
	fgets(profile[0], 25, Dat);
	fclose(Dat);

	if ( strcmp(profile[0], "MainManuConnect = 0") == 0 ){
		return 0;
	}else if ( strcmp(profile[0], "MainManuConnect = 1") == 0 ){
		return 1;
	}else if ( strcmp(profile[0], "MainManuConnect = 2") == 0 ){
		return 2;
	}else if ( strcmp(profile[0], "MainManuConnect = 3") == 0 ){
		return 3;
	}else{
		return 0;
	}
}

void Detail_Change_Mode(int Dat_Check){
	system("cls");
	int ch;
	FILE *Detail;
	printf("\t속성 재설정\n\n");
	printf("1. 메인 메뉴 - 시작시 메인메뉴로 들어갑니다.\n\n");
	printf("2. 에러 검출 - 문법만 처리합니다.\n\n");
	printf("3. 정밀 검출 - 모든 에러를 처리합니다. 하지만 에러 검출속도가 느립니다.\n\n");
	printf("4. 파일 구동 - 에러가 걸리면 무시하고 계속합니다.\n\n");
	printf("ESC. 뒤로 가기 - 메인 메뉴로 이동을 합니다.\n\n\n\n");
	printf("추신 - 번호만 눌리시면은 됩니다. : ");
	for (;;){
		ch = getch();
		switch (ch){
		case '2' :
			Detail = fopen("KBL.Dat", "wt+");
			fprintf(Detail, "MainManuConnect = 1");
			fclose(Detail);
			MainFunc(Dat_Check);
			break;
		case '3' :
			Detail = fopen("KBL.Dat", "wt+");
			fprintf(Detail, "MainManuConnect = 2");
			fclose(Detail);
			MainFunc(Dat_Check);
			break;
		case '4' :
			Detail = fopen("KBL.Dat", "wt+");
			fprintf(Detail, "MainManuConnect = 3");
			fclose(Detail);
			MainFunc(Dat_Check);
			break;
		case '1' :
			Detail = fopen("KBL.Dat", "wt+");
			fprintf(Detail, "MainManuConnect = 0");
			fclose(Detail);
			MainFunc(Dat_Check);
			break;
		case 27 :
			MainFunc(Dat_Check);
			break;
		default :
			continue;
			break;
		}
	}
}

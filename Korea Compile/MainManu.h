void MainFunc(int Dat_Check){
	system("cls");
	switch (Dat_Check){
	case 0 :
		break;
	case 1 :
	case 3 :
		printf("�Ӽ����� �Դϴ�.");
		getch();
		exit(1);
		break;
	case 2 :
		MicroTest();
	default :
		printf("�Ӽ� ����");
		getch();
		exit(1);
		break;
	}
	
	int ch;
	printf("\t��� ���� ���ּ���.\n\n");
	printf("1. ���� ���� - ������ ó���մϴ�.\n\n");
	printf("2. ���� ���� - ��� ������ ó���մϴ�. ������ ���� ����ӵ��� �����ϴ�.\n\n");
	printf("3. ���� ���� - ������ �ɸ��� �����ϰ� ����մϴ�.\n\n");
	printf("4. �Ӽ� ���� - �Ӽ��� �������մϴ�.\n\n");
	printf("ESC. ���� �ϱ� - ���α׷��� ���Ḧ �մϴ�.\n\n\n\n");
	printf("�߽� - ��ȣ�� �����ø��� �˴ϴ�. : ");
	for (;;){
		ch = getch();
		switch ( ch ){
		case '1' :
			printf("�̱��� �Դϴ�.");
			
			break;
		case '2' :
			MicroTest();
			break;
		case '3' :
			printf("�̱��� �Դϴ�.");
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
	printf("\t�Ӽ� �缳��\n\n");
	printf("1. ���� �޴� - ���۽� ���θ޴��� ���ϴ�.\n\n");
	printf("2. ���� ���� - ������ ó���մϴ�.\n\n");
	printf("3. ���� ���� - ��� ������ ó���մϴ�. ������ ���� ����ӵ��� �����ϴ�.\n\n");
	printf("4. ���� ���� - ������ �ɸ��� �����ϰ� ����մϴ�.\n\n");
	printf("ESC. �ڷ� ���� - ���� �޴��� �̵��� �մϴ�.\n\n\n\n");
	printf("�߽� - ��ȣ�� �����ø��� �˴ϴ�. : ");
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

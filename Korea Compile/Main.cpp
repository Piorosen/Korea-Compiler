#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
#include <io.h>
#include <time.h>
#include <direct.h>
#define PROFILE_FIRST 1
#define MAX 256
#define cls() system("cls")

class Var{
public:
	char **Char_Var_Data;
	int Char_Count;
	char **Char_Var_Name;
	
	float *Float_Var_Data;
	int Float_Count;
	char **Float_Var_Name;
	
	int *Int_Var_Data;
	int Int_Count;
	char **Int_Var_Name;

	bool *Bool_Var_Data;
	int Bool_Count;
	char **Bool_Var_Name;

	FILE *(*File_Var_Data);
	int File_Count;
	char **File_Var_Name;
	
	bool List(char *Name, Var Var);
	bool Name_Check(char *Name);
};

struct UsingFunc{
	bool Basic;
	bool System;
	bool String;
	bool File;
	bool Math;
};

void MicroTest();
void Detail_Change_Mode(int Dat_Check);
struct UsingFunc UsingFile(char Name[256], int Error_Code_Line);

#include "Main.h"
#include "Data ���ϱ�.h"
#include "MainManu.h"
#include "Var.h"
#include "Function.h"

#include <process.h>

void main(){
	time_t curr;
	struct tm *d;
	int Data[3] = {0,};
	int Dat_Check;
	Dat_Check = Dat();
	MainFunc(Dat_Check);
}

UsingFunc UsingFile(char *Name, int Error_Code_Line, struct UsingFunc Data){
	struct UsingFunc UsingFunc = Data;
	char Using[256];
	sprintf(Using, "%s %s", "Using", Name);
	if (strcmp(Name, "<BASIC.K>") == 0){
		UsingFunc.Basic = true;
		return UsingFunc;
	}else if(strcmp(Name, "<SYSTEM.K>") == 0){
		UsingFunc.System = true;
		return UsingFunc;
	}else if (strcmp(Name, "<STRING.K>") == 0){
		UsingFunc.String = true;
		return UsingFunc;
	}else if (strcmp(Name, "<FILE.K>") == 0){
		UsingFunc.File = true;
		return UsingFunc;
	}else if (strcmp(Name, "<MATH.K>") == 0){
		UsingFunc.Math = true;
		return UsingFunc;
	}else{
		Error_Solve(Using, "Using �� �Ҽ� �ִ� ������ �����ϴ�.", Error_Code_Line);
		return UsingFunc;
	}
}

void MicroTest(){
	cls();
	srand((int)time(NULL));
	bool Check_Code = false;
	int Using_Int = 1;
	struct UsingFunc UsingFunc = {0,};
	char Using[2][256] = {0,};

	if (access("Using Function.txt", 0) == -1){
		FILE *Function = fopen("Using Function.txt", "w+");
		fprintf(Function, "Using <Basic.K>\nUsing <System.K>\nUsing <String.K>\nUsing <File.K>\nUsing <Math.K>\nEnd");
		fclose(Function);
	}
	FILE *Func = fopen("Using Function.txt", "r+");

	for(;;Using_Int++){
		fscanf(Func, "%s", Using[0]);
		if (Using[0][0] == 0){
			Error_Solve("�ҽ��ڵ尡 ����ֽ��ϴ�.", "��ɾ �Է��� �ּ���!", 1);
		}
		char temp[256] = {0,};
		strcat(temp, Using[0]);
		strupr(Using[0]);
		if (strcmp(Using[0], "USING") == 0){
			fscanf(Func, "%s", Using[1]);
			strupr(Using[1]);
			UsingFunc = UsingFile(Using[1], Using_Int, UsingFunc);
		}else if (strcmp(Using[0], "END") == 0){
			break;
		}else{
			Error_Solve(temp, "���ڸ� �߸� �Է� �ϼ̽��ϴ�.", Using_Int);
		}
	}
	
	Var Var;

	Var.Char_Count = 1;
	Var.Float_Count = 1;
	Var.Int_Count = 1;
	Var.Bool_Count = 1;
	Var.File_Count = 1;

	Var.Char_Var_Name = 0;
	Var.Float_Var_Name = 0;
	Var.Int_Var_Name = 0;
	Var.Bool_Var_Name = 0;
	Var.File_Var_Name = 0;

	int Error_Code_Line=1;

	char Input[256] = {0,};
	char I_temp[256] = {0,};

	int i = 1;

	if (access("Source Code File.txt", 0) == -1){
		FILE *DataRead1 = fopen("Source Code File.txt", "w+");
		fprintf(DataRead1, "������� \"�̿��� �ּż� �����Ϲ��ϴ�.\"\n����\n����\n�����ǳ�");
		fclose(DataRead1);
	}
	FILE *DataRead = fopen("Source Code File.txt", "r+");
	int File_Deap = 2;
	int *File_Line = 0;
	char **File_Name = 0;

	for (;;Error_Code_Line++){
		Check_Code = false;
		fscanf(DataRead, "%s ", &Input);
Main:
		if (Input[0] == 0){Error_Solve("�ҽ��ڵ尡 ����ֽ��ϴ�.", "��ɾ �Է��� �ּ���!", 1);}
		if (UsingFunc.Basic){
			if (strcmp(Input, "����") == 0){
				fscanf(DataRead, "%s", Input);
				if (strcmp(Input, "����") == 0){
					continue;
				}else{
					exit(1);
				}
			}
			else if (strcmp(Input, "Ű�Է�") == 0){
				Check_Code = true;
				fscanf(DataRead, "%s", Input);
				bool Check = Var.List(Input, Var);
				int i = 0;
				if (Check == false){
					sprintf(Input, "Ű�Է� %s", Input);
					Error_Solve(Input, "������ �ƴѰ��� ������ �̿� �ϼ̽��ϴ�.", Error_Code_Line);
				}else{
					for (;;i++){
						if (Var.Int_Count != 1){
							if ((strcmp(Input, Var.Int_Var_Name[i]) == 0)  && (Var.Int_Count - 1) > i ){
								*(Var.Int_Var_Data+i) = getch();
								fscanf(DataRead, "%s ", Input);
								goto Main;
							}
						}else if ((Var.Int_Count - 1) <= i){
							sprintf(Input, "Ű�Է� %s", Input);
							Error_Solve(Input, "������ �����ϴ�.(�������� ȣȯ�� �˴ϴ�.)", Error_Code_Line);
						}
					}
				}
			}else if (strcmp(Input, "�����Է�") == 0){
				Check_Code = true;
				fscanf(DataRead, "%s", Input);
				bool Check = Var.List(Input, Var);
				int i = 0;
				if (Check == false){
					sprintf(Input, "�����Է� %s", Input);
					Error_Solve(Input, "������ �ƴѰ��� ������ �̿� �ϼ̽��ϴ�.", Error_Code_Line);
				}else{
					for (;;i++){
						if (Var.Char_Count != 1){
							if ((strcmp(Input, Var.Char_Var_Name[i]) == 0)  && (Var.Char_Count - 1) > i ){
								gets(*(Var.Char_Var_Data+i));
								fscanf(DataRead, "%s ", Input);
								goto Main;
							}
						}else if ((Var.Char_Count - 1) <= i){
							sprintf(Input, "�����Է� %s", Input);
							Error_Solve(Input, "������ �����ϴ�.(�������� ȣȯ�� �˴ϴ�.)", Error_Code_Line);
						}
					}
				}
			}else if (strcmp(Input, "�����Է�") == 0){
				Check_Code = true;
				fscanf(DataRead, "%s", Input);
				bool Check = Var.List(Input, Var);
				int i = 0;
				if (Check == false){
					sprintf(Input, "�����Է� %s", Input);
					Error_Solve(Input, "������ �ƴѰ��� ������ �̿� �ϼ̽��ϴ�.", Error_Code_Line);
				}else{
					for (;;i++){
						if (Var.Char_Count != 1){
							if ((strcmp(Input, Var.Char_Var_Name[i]) == 0)  && (Var.Char_Count - 1) > i ){
								scanf("%s", *(Var.Char_Var_Data+i));
								fscanf(DataRead, "%s ", Input);
								goto Main;
							}
						}else if ((Var.Char_Count - 1) <= i){
							sprintf(Input, "�����Է� %s", Input);
							Error_Solve(Input, "������ �����ϴ�.(�������� ȣȯ�� �˴ϴ�.)", Error_Code_Line);
						}
					}
				}
			}else if (strcmp(Input, "����") == 0){		// ���� [Data] [Op] [Data] / ���� ����
				Check_Code = true;
				bool Check;
				fscanf(DataRead, "%s ", Using[0]);
				if (strcmp(Using[0], "Ű�Է�") == 0){
					if (kbhit()){
						fscanf(DataRead, "%s", Input);
						bool Check = Var.List(Input, Var);
						int i = 0;
						if (Check == false){
							sprintf(Input, "���� Ű�Է� %s", Input);
							Error_Solve(Input, "������ �ƴѰ��� ������ �̿� �ϼ̽��ϴ�.", Error_Code_Line);
						}else{
							for (;;i++){
								if (Var.Int_Count != 1){
									if ((strcmp(Input, Var.Int_Var_Name[i]) == 0)  && (Var.Int_Count - 1) > i ){
										*(Var.Int_Var_Data+i) = getch();
										fscanf(DataRead, "%s ", Input);
										goto Main;
									}
								}else if ((Var.Int_Count - 1) <= i){
									sprintf(Input, "���� Ű�Է� %s", Input);
									Error_Solve(Input, "������ �����ϴ�.(�������� ȣȯ�� �˴ϴ�.)", Error_Code_Line);
								}
							}
						}
					}else{
						fscanf(DataRead, "%s ", Input);
						goto Main;
					}
				}
				sprintf(Input, "%s %s", Using[0], Using[1]);
				Check = IF(Input, Error_Code_Line,DataRead, Var);
				if (Check == true){
					goto Main;
				}else{
					for(;;){
						fscanf(DataRead, "%s ", Input);
IF_BACK:
						if (strcmp(Input, "����") == 0){
							fscanf(DataRead, "%s", Input);
							if (strcmp(Input, "����") == 0){
								fscanf(DataRead, "%s ", Input);
								goto Main;
							}else{
								goto IF_BACK;
							}
						}else{
							continue;
						}
					}
				}
			}else if (strcmp(Input, "�����ǳ�") == 0 && File_Deap != 2){
				Check_Code = true;
				int i;
				DataRead = fopen(File_Name[File_Deap - 3], "r");
				File_Deap-=1;
				for (i = 0; i < File_Line[File_Deap - 2]; i++){
					fgets(Input, 256, DataRead);
				}
				Error_Code_Line = File_Line[File_Deap - 2];
			}else if (strcmp(Input, "�����ǳ�") == 0 && File_Deap == 2){exit(1);}
			else if (strcmp(Input, "//") == 0){Check_Code = true;fgets(Input, 256, DataRead);}
			else if (strcmp(Input, "/*") == 0){Check_Code = true;for(;;){fscanf(DataRead, "%s", Input);if (strcmp(Input, "*/") == 0)break;}}
			else if (strcmp(Input , ":") == 0){						// goto���� ���Ѱ�
				Check_Code = true;
				fgets(Input, 256, DataRead);
				continue;
			}else if (strcmp(Input, "�̵�") == 0){
				Check_Code = true;
				fscanf(DataRead, "%s", &Input);
				fclose(DataRead);
				DataRead = fopen("Source Code File.txt", "r+");
				File_Deap = 2;
				char temp[256] = {0,};
				for(;;){
					fscanf(DataRead, "%s", &temp);
					sprintf(I_temp, "%s%s", ": ", Input);
					if (strcmp(Input, "�߰��ڵ�") == 0){
						Check_Code = true;
						fgets(Input, 256, DataRead);
						char *Data = 0;
						Data = Quotation_Marks(Input);
						if(access(Data, 0) == -1 && access(Data, 4) == -1){
							char a[256] = {0,};
							sprintf(a, "%s %s", "�߰��ڵ�", Input);
							Error_Solve(a, "������ ���� ���� �ʽ��ϴ�.", Error_Code_Line);
						}
						File_Deap+=1;
						if (File_Deap == 3){
							File_Name = (char **)calloc(File_Deap, sizeof(char*));
							File_Name[File_Deap] = (char *)calloc(strlen(Input), sizeof(char));
							File_Line = (int *)calloc(sizeof(int), File_Deap);
							*(File_Name + (File_Deap - 3)) = "Source Code File.txt";
							File_Line[File_Deap - 3] = Error_Code_Line;
						}else{
							File_Name = (char **)realloc(File_Name, sizeof(char*) * File_Deap);
							File_Name[File_Deap] = (char *)calloc(strlen(Input), sizeof(char));
							File_Line = (int *)realloc(File_Line, sizeof(int) * File_Deap);
						}
						*(File_Name + (File_Deap - 2)) = Input;
						File_Line[File_Deap - 3] = Error_Code_Line;
						fclose(DataRead);
						DataRead = fopen(Data, "r+");
						Error_Code_Line = 1;
					}else if (strcmp(Input, "�����ǳ�") == 0 && File_Deap != 2){
						Check_Code = true;
						int i;
						DataRead = fopen(File_Name[File_Deap - 3], "r");
						File_Deap-=1;
						for (i = 0; i < File_Line[File_Deap - 2]; i++){
							fgets(Input, 256, DataRead);
						}
						Error_Code_Line = File_Line[File_Deap - 2];	
					}
					if (strcmp(Input, "�����ǳ�") == 0 && File_Deap == 2){ Error_Solve(I_temp, "������ �� �� �����Ͽ����ϴ�.", Error_Code_Line);}
					if (strcmp(Input, temp) == 0)break;
				}
			}else if (strcmp(Input, "�������") == 0){
				Check_Code = true;
				fgets(Input, MAX, DataRead);
				printVX(Input, Error_Code_Line);
			}
			else if (strcmp(Input, "����") == 0){Check_Code = true;getch();}
			else if (strcmp(Input, "�������") == 0){
				Check_Code = true;
				fscanf(DataRead, "%s", Input);
				printVO(Input, Error_Code_Line, Var);
			}// ���� ������ INT
			else if (strcmp(Input, "������") == 0){
				Check_Code = true;
				bool Check[2];
				fscanf(DataRead, "%s ", &Input);
				sprintf(I_temp, "%s%s ", "������ ", Input);
				int len = strlen(Input);
				if ( len > 26 ) {Error_Solve(I_temp, "���� �̸� �ִ�ġ�� 26byte�Դϴ�.", Error_Code_Line);}

				Check[0] = Var.Name_Check(Input);
				Check[1] = Var.List(Input, Var);
				if(Check[1] == true)
					Error_Solve(I_temp, "�� �̸����� ������ �Ұ����մϴ�.", Error_Code_Line);
				Var.Int_Count+=1;
				if (Var.Int_Count == 2){
					Var.Int_Var_Name = (char **)calloc(Var.Int_Count, sizeof(char*));
					Var.Int_Var_Name[Var.Int_Count - 2] = (char *)calloc(26, sizeof(char));
					Var.Int_Var_Data = (int *)calloc(Var.Int_Count, sizeof(int));
				}else{
					Var.Int_Var_Name = (char **)realloc(Var.Int_Var_Name, sizeof(char*) * Var.Int_Count);
					Var.Int_Var_Name[Var.Int_Count - 2] = (char *)calloc(26, sizeof(char));
					Var.Int_Var_Data = (int *)realloc(Var.Int_Var_Data, sizeof(int) * Var.Int_Count);
				}
				strcpy(Var.Int_Var_Name[Var.Int_Count - 2], Input);
				fscanf(DataRead, "%s ", Input);
				sprintf(I_temp, "%s%s ", I_temp, Input);
				if (strcmp(Input, "=") == 0){
					char Input[256] = {0,};
					fscanf(DataRead, "%s", &Input);
					sprintf(I_temp, "%s%s ", I_temp, Input);
					Var.Int_Var_Data[Var.Int_Count - 2] = Int_Data(Input, Var);
				}
				else Var.Int_Var_Data[Var.Int_Count - 2] = 0;

			}// ���� ������ CHAR
			else if (strcmp(Input, "������") == 0){
				Check_Code = true;
				bool Check[2];
				fscanf(DataRead, "%s ", &Input);
				sprintf(I_temp, "%s%s ", "������ ", Input);
				int len = strlen(Input);
				if ( len > 26 ) {Error_Solve(I_temp, "���� �̸� �ִ�ġ�� 26byte�Դϴ�.", Error_Code_Line);}

				Check[0] = Var.Name_Check(Input);
				Check[1] = Var.List(Input, Var);
				if(Check[1] == true)
					Error_Solve(I_temp, "�� �̸����� ������ �Ұ����մϴ�.", Error_Code_Line);
				Var.Char_Count+=1;
				if (Var.Char_Count == 2){
					Var.Char_Var_Name = (char **)calloc(Var.Char_Count, sizeof(char*));
					Var.Char_Var_Name[Var.Char_Count - 2] = (char *)calloc(26, sizeof(char));
					Var.Char_Var_Data = (char **)calloc(Var.Char_Count, sizeof(char*));
				}else{
					Var.Char_Var_Name = (char **)realloc(Var.Char_Var_Name, sizeof(char*) * Var.Char_Count);
					Var.Char_Var_Name[Var.Char_Count - 2] = (char *)calloc(26, sizeof(char));
					Var.Char_Var_Data = (char **)realloc(Var.Char_Var_Data, sizeof(char*) * Var.Char_Count);
				}
				strcpy(Var.Char_Var_Name[Var.Char_Count - 2], Input);
				fscanf(DataRead, "%s ", Input);
				sprintf(I_temp, "%s%s ", I_temp, Input);
				if (strcmp(Input, "=") == 0){
					char *Data;
					fgets(Input, 256, DataRead);
					sprintf(I_temp, "%s%s", I_temp, Input);
					Data = Quotation_Marks(Input, '\"', true);
					*(Var.Char_Var_Data + (Var.Char_Count - 2)) = Data;
				}
				else{*(Var.Char_Var_Data + (Var.Char_Count - 2)) = "�� ������ ����� �Դϴ�.";goto Main;};
			}
		}if (UsingFunc.System){
			if (strcmp(Input, "�ý���") == 0){
				Check_Code = true;
				fgets(Input, MAX, DataRead);
				Quotation_Marks(Input, '\"', true);
				system(Input);
			}
		}if (UsingFunc.String){
			if (strcmp(Input, "����") == 0){
				fscanf(DataRead, "%s ", Input);
				if (strcmp(Input, "����") == 0){
					Check_Code = true;
					int i = 0;
					int Num[2];
					bool Check[2] = {false,};
					fscanf(DataRead, "%s %s ", Using[0], Using[1]);
					for (;Var.Char_Count > i ;i++){
						if (Var.Char_Count != 1){
							if (strcmp(Using[0], Var.Char_Var_Name[i]) == 0){
								Check[0] = true;
								Num[0] = i;
							}if (strcmp(Using[1], Var.Char_Var_Name[i]) == 0){
								Check[1] = true;
								Num[1] = i;
							}
						}
						if (Check[0] == true && Check[1] == true){
							strcpy(Var.Char_Var_Data[Num[0]], Var.Char_Var_Data[Num[1]]);
							fscanf(DataRead, "%s ", Input);
							goto Main;
						}if (Check[0] == true && Check[1] == false){
							if (Var.Char_Count > i){
								strcpy(Var.Char_Var_Data[Num[0]], Using[1]);
								fscanf(DataRead, "%s ", Input);
								goto Main;
							}else{
								continue;
							}
						}
					}
					sprintf(Input, "���� ���� %s %s", Using[0], Using[1]);
					Error_Solve(Input, "���ڿ��� ������ �Է� �ϼ̽��ϴ�.(�������� ȣȯ�� �˴ϴ�.)", Error_Code_Line);
				}else if (strcmp(Input, "����") == 0){ // ���� ���� [����1] [��1]
					Check_Code = true;
					int i = 0;
					int Num[2];
					bool Check[2] = {false,};
					fscanf(DataRead, "%s ", Using[0]);
					fgets(Using[1], 256, DataRead);
					for (;;i++){
						if (Var.Char_Count != 1){
							if (strcmp(Using[0], Var.Int_Var_Name[i]) == 0){
								Check[0] = true;
								Num[0] = i;
							}
						}else if (Var.Int_Count != 1){
							if (strcmp(Using[1], Var.Char_Var_Name[i]) == 0){
								Check[1] = true;
								Num[1] = i;
							}
						}
						if (Check[0] == true && Check[1] == true){
							Var.Int_Var_Data[Num[1]] = strlen(Var.Char_Var_Data[Num[0]]);
							fscanf(DataRead, "%s ", Input);
							goto Main;
						}if (Var.Char_Count > i){
							if (Check[1] == true){
								Var.Int_Var_Data[Num[0]] = strlen(Using[1]);
								fscanf(DataRead, "%s ", Input);
								goto Main;
							}else{
								Error_Solve(Input, "���� ���� [����������] <- �� �κ��� ������ �ƴմϴ�.", Error_Code_Line);
							}
						}else if (Var.Int_Count > i){
							sprintf(Input, "���� ���� %s %s", Using[0], Using[1]);
							Error_Solve(Input, "���� : ���� ���� [����1] [��1]", Error_Code_Line);
						}
					}
				}else if (strcmp(Input, "��ġ����") == 0){
					Check_Code = true;
					char x[256], y[256];
					fscanf(DataRead, "%s %s", x, y);
					gotoxy(x,y, Error_Code_Line, Var);
				}
			}
		}if (UsingFunc.File){
			if (strcmp(Input, "������") == 0){				// ������ [�����̸�] = [�����̸�] # [���]
				Check_Code = true;
				bool Check[2];
				fscanf(DataRead, "%s ", &Input);
				sprintf(I_temp, "%s%s ", "������ ", Input);
				int len = strlen(Input);
				if ( len > 26 ) {Error_Solve(I_temp, "���� �̸� �ִ�ġ�� 26byte�Դϴ�.", Error_Code_Line);}
				Check[0] = Var.Name_Check(Input);
				Check[1] = Var.List(Input, Var);
				if(Check[1] == true)
					Error_Solve(I_temp, "�� �̸����� ������ �Ұ����մϴ�.", Error_Code_Line);
				Var.File_Count+=1;
				if (Var.File_Count == 2){
					Var.File_Var_Name = (char **)calloc(Var.File_Count, sizeof(char*));
					Var.File_Var_Name[Var.File_Count - 2] = (char *)calloc(26, sizeof(char));
					Var.File_Var_Data = (FILE **)calloc(Var.File_Count, sizeof(FILE *));
				}else{
					Var.File_Var_Name = (char **)realloc(Var.File_Var_Name, sizeof(char*) * Var.File_Count);
					Var.File_Var_Name[Var.File_Count - 2] = (char *)calloc(26, sizeof(char));
					Var.File_Var_Data = (FILE **)realloc(Var.File_Var_Data, sizeof(FILE *) * Var.File_Count);
				}
				strcpy(Var.File_Var_Name[Var.File_Count - 2], Input);
				fscanf(DataRead, "%s ", Input);
				sprintf(I_temp, "%s%s ", I_temp, Input);
				if (strcmp(Input, "=") == 0){
					fgets(Input, 256, DataRead);
					sprintf(I_temp, "%s%s ", I_temp, Input);
					char *T_Input;
					char *TextName;
					char *Mode;
					T_Input = Quotation_Marks(Input);
					TextName = Next_Sentence(T_Input, true);
					Mode = Next_Sentence(T_Input);
					int i = 0;
					Var.File_Var_Data[Var.File_Count - 2] = fopen(TextName, Mode);
				}else Var.File_Var_Data[Var.File_Count - 2] = 0;
			}else if (strcmp(Input, "���Ͽ���") == 0){
				Check_Code = true;
				bool Check[2];
				fscanf(DataRead, "%s ", &Input);
				sprintf(I_temp, "%s%s ", "������ ", Input);
				int len = strlen(Input);
				if ( len > 26 ) {Error_Solve(I_temp, "���� �̸� �ִ�ġ�� 26byte�Դϴ�.", Error_Code_Line);}
				Check[0] = Var.Name_Check(Input);
				Check[1] = Var.List(Input, Var);
				if (Check[0] == false || Check[1] == true)
					Error_Solve(I_temp, "���� �̸��� ������ �ְų�, �� �̸����� ������ �Ұ����մϴ�.", Error_Code_Line);

			}else if (strcmp(Input, "����") == 0){
				fscanf(DataRead, "%s ", Input);
				if (strcmp(Input, "�����б�") == 0){ // ���� �����б� [�����̸�] # [�����̸�]
					Check_Code = true;
					char temp[256] = {0,};
					char *FileName = 0;
					char *Mode = 0;
					char *VarName = 0;
					bool Check[2];


					fgets(temp, 256, DataRead);
					sprintf(I_temp, "%s %s", "���� �����б�", temp);
					FileName = Next_Sentence(temp, true);
					VarName = Next_Sentence(temp);
					Check[0] = Var.List(FileName, Var);
					Check[1] = Var.List(VarName, Var);

					if (Check[0] == false){
						Error_Solve(I_temp, "���ڿ��� ������ �̿��Ҽ� �����ϴ�.", Error_Code_Line);
					}if (Check[1] == false){
						Error_Solve(I_temp, "���ڿ��� ������ �̿��Ҽ� �����ϴ�.", Error_Code_Line);
					}
					Check[0] = false;
					Check[1] = false;
					int Num = 0;
					int FileNum, VarNum;
					for(;;Num++){
						if (strcmp(*(Var.File_Var_Name+Num), FileName) == 0){
							FileNum = Num;
							Check[0] = true;
						}if (strcmp(*(Var.Char_Var_Name+Num), VarName) == 0){
							VarNum = Num;
							Check[0] = true;
						}if (Check[0] == true && Check[1] == true){
							fgets(*(Var.Char_Var_Data+VarNum), 256, *(Var.File_Var_Data+FileNum));
							break;
						}
					}
				}else if (strcmp(Input, "����") == 0){

				}
			}else if (strcmp(Input, "�߰��ڵ�") == 0){			// �߰��ڵ� "[�̸�]"
				Check_Code = true;
				fgets(Input, 256, DataRead);
				char *Data = 0;
				Data = Quotation_Marks(Input);
				if(access(Data, 0) == -1 && access(Data, 4) == -1){
					char a[256] = {0,};
					sprintf(a, "%s %s", "�߰��ڵ�", Input);
					Error_Solve(a, "������ ���� ���� �ʽ��ϴ�.", Error_Code_Line);
				}
				File_Deap+=1;
				if (File_Deap == 3){
					File_Name = (char **)calloc(File_Deap, sizeof(char*));
					File_Name[File_Deap] = (char *)calloc(strlen(Input), sizeof(char));
					File_Line = (int *)calloc(sizeof(int), File_Deap);
					*(File_Name + (File_Deap - 3)) = "Source Code File.txt";
					File_Line[File_Deap - 3] = Error_Code_Line;
				}else{
					File_Name = (char **)realloc(File_Name, sizeof(char*) * File_Deap);
					File_Name[File_Deap] = (char *)calloc(strlen(Input), sizeof(char));
					File_Line = (int *)realloc(File_Line, sizeof(int) * File_Deap);
				}
				*(File_Name + (File_Deap - 2)) = Input;
				File_Line[File_Deap - 3] = Error_Code_Line;
				fclose(DataRead);
				DataRead = fopen(Data, "r+");
				Error_Code_Line = 1;
			}
		}if (UsingFunc.Math){
			if (strcmp(Input, "����") == 0){
				Check_Code = true;
				fscanf(DataRead, "%s ", Input);
				fscanf(DataRead, "%s ", Using[0]);
				int i = 0;
				int k;
				if (Var.List(Input, Var)){
					for (;;i++){
						if (Var.Int_Count != 1){
							if ((strcmp(Input, Var.Int_Var_Name[i]) == 0)  && (Var.Int_Count - 1) > i ){
								k = Int_Data(Using[0], Var);
								*(Var.Int_Var_Data + i) += k;
								fscanf(DataRead, "%s ", Input);
								goto Main;
							}else{
								continue;
							}
						}
					}
				}else{
					fgets(Using[0], 256, DataRead);
					sprintf(Input, "���� %s %s", Input, Using[0]);
					Error_Solve(Input, "���ڿ��� ������ �Է� �ϼ̽��ϴ�.(�������� ȣȯ�� �˴ϴ�.)", Error_Code_Line);
				}
			}else if (strcmp(Input, "����") == 0){
				Check_Code = true;
				fscanf(DataRead, "%s ", Input);
				fscanf(DataRead, "%s ", Using[0]);
				int i = 0;
				int k;
				if (Var.List(Input, Var)){
					for (;;i++){
						if (Var.Int_Count != 1){
							if ((strcmp(Input, Var.Int_Var_Name[i]) == 0)  && (Var.Int_Count - 1) > i ){
								k = Int_Data(Using[0], Var);
								*(Var.Int_Var_Data + i) -= k;
								fscanf(DataRead, "%s ", Input);
								goto Main;
							}else{
								continue;
							}
						}
					}
				}else{
					fgets(Using[0], 256, DataRead);
					sprintf(Input, "���� %s %s", Input, Using[0]);
					Error_Solve(Input, "���ڿ��� ������ �Է� �ϼ̽��ϴ�.(�������� ȣȯ�� �˴ϴ�.)", Error_Code_Line);
				}
			}else if (strcmp(Input, "����") == 0){
				Check_Code = true;
				int Data;
				fscanf(DataRead, "%s ", Input);
				int i = 0;
				if (Var.List(Input, Var)){
					fscanf(DataRead, "%s ", Using[0]);
					if (Var.List(Input, Var)){
						Data = Int_Data(Using[0], Var);
					}else{
						Data = atoi(Using[0]);
					}
				}else{
					Error_Solve(Input, "���ڿ��� ������ �Է� �ϼ̽��ϴ�.", Error_Code_Line);
				}
				for (;;i++){
					if (Var.Int_Count != 1){
						if ((strcmp(Input, Var.Int_Var_Name[i]) == 0)  && (Var.Int_Count - 1) > i ){
							*(Var.Int_Var_Data + i) = Data;
							fscanf(DataRead, "%s ", Input);
							goto Main;
						}else{
							continue;
						}
					}
				}
			}else if (strcmp(Input, "����") == 0){ // ���� [����] # [��1] + [��2] #
				Check_Code = true;
				fscanf(DataRead, "%s ", Input);
				fgets(Using[0], 256, DataRead);
				int i = 0;
				int Num = 0;
				if (Var.List(Input, Var)){
					for (;;i++){
						if (strcmp(Input, *(Var.Int_Var_Name + i)) == 0){
							Num = i;
							break;
						}else if (Var.Int_Count <= i){
							sprintf(Using[1], "���� %s %s", Input, Using[0]);
							Error_Solve(Using[1], "������ �������� ������ ������ �ƴմϴ�.", Error_Code_Line);
						}else{
							continue;
						}
					}
				}else{
					sprintf(Input, "���� %s %s", Input, Using[0]);
					Error_Solve(Input, "���ڿ��� ������ �Է� �ϼ̽��ϴ�.", Error_Code_Line);
				}
				char *Data;
				char *Data1;
				char *Data2;
				int I_Data[2];
				Data = Quotation_Marks(Using[0], '#', true);
				Data1 = Next_Sentence(Data, '+', true);
				Data2 = Next_Sentence(Data, '+');
				I_Data[0] = Int_Data(Data1, Var);
				I_Data[1] = Int_Data(Data2, Var);
				if (I_Data[0] <= 0){
					sprintf(Using[1], "���� %s %s", Input, Using[0]);
					Error_Solve(Using[1], "���� # [��1] + [��2] # ���� [��1]�� 0 �Ǵ� ������ �ɼ��� �����ϴ�.", Error_Code_Line);
				}
				*(Var.Int_Var_Data + Num)  = rand()%I_Data[0] + I_Data[1];
			}
		}if (!Check_Code){
			Error_Solve(Input, "�ҽ��ڵ忡 ������ �ֽ��ϴ�.", Error_Code_Line);
		}
	}
}
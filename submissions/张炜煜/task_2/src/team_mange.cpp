#include "team_mange.h"
//��ϵͳ�������棬�г���Ա���г�������Ϣ

using namespace std;
Menu_Options choices;
member members;
attendance attendances;
int Menu_Select(void)		//ѡ������ѡ��Ϊ����ֵ��ѡ����ֵΪ-1��
{	
	cout << "      ��Ա����ϵͳ"       << endl;
	cout << "=======================" << endl;
	cout << "1.�����Ա" << endl;
	cout << "2.ɾ����Ա" << endl;
	cout << "3.�г�������Ա" << endl;
	cout << "4.�޸���Ա��Ϣ" << endl;
	cout << "5.��ѯ������Ϣ" << endl;
	cout << "6.�޸Ŀ�����Ϣ" << endl;
	cout << "0.�˳�" << endl;
	cout << "����������ѡ��:";

	wstring choice;
	getline(wcin, choice);
	choice.erase(remove_if(choice.begin(), choice.end(), ::isspace), choice.end());

	if (choice.length() == 1 && all_of(choice.begin(), choice.end(), ::isdigit))	//�ж�
	{
		if(stoi(choice)>=0 && stoi(choice) <= 6)
		{
			system("cls");
			return stoi(choice);
		}else{
			cout << "\n�޴�ѡ��,���������롣";	//�������ֳ���
			system("pause");
			
			return -1;				
		}		
	}else{
		cout << "\n��Ч����,�밴��ʾ��������";	//���������
		system("pause");
		system("cls");
		return -1;
	}
}


void Menu_Option(int choice)	//ִ�к�����ִ�и�������
{	
	
	switch (choice)
	{	
		case quit:
			break;
		case entry_member:						
			members.AddMember();
			system("pause");
			system("cls");
			break;
		case remove_member:
			members.DeleteMember();
			break;
		case print_members:
			system("cls");
			PrintMembers();
			system("pause");
			system("cls");
			break;
		case revise_members:
			members.ChangeMember();
			break;
		case read_attendence:
			attendances.Show_Attendance();
			break;
		case revise_attendence:
			attendances.Clock_In();
			break;				
		default:
			break;
	}

}



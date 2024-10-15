#include "attendance.h"

attendance::attendance(){}
attendance::attendance(wstring ID, string time, int frequency, float worktime , float sum_worktime) :
	_ID(ID),
	_time(time),
	_frequency(frequency),
	_worktime(worktime),
	_sum_worktime(sum_worktime){}


int isMember(vector<attendance>& attendance_vector, const wstring& input)
{
	for(int i = 0; i < attendance_vector.size(); i++)
	{
		if( attendance_vector[i]._ID == input)
		{
			return i;
		}
	}
	return -1;
}

void attendance::Clock_In()
{
	//ѧ��
	wstring ID;
	do{
		cout << "\n������ѧ��: ";
		getline(wcin, ID);
		ID.erase(remove_if(ID.begin(), ID.end(), ::iswspace), ID.end());		
		if (ID.length() == 11 && all_of(ID.begin(), ID.end(), ::isdigit))
		{
			_ID=ID;
			break;		
		}
		else
		{
			cout << "ѧ�Ÿ�ʽ����ȷ,������11λ����" << endl;
			system("pause");
		}
	}while (1);

	//����ʱ��
	wstring worktime;
	do{
		cout << "\n�����빤��ʱ��(��λ:Сʱ): ";
		getline(wcin, worktime);
		worktime.erase(remove_if(worktime.begin(), worktime.end(), ::iswspace), worktime.end());		
		if (all_of(worktime.begin(), worktime.end(), ::isdigit))
		{

			wstring_convert<codecvt_utf8_utf16<wchar_t>> converter;
    		string f_worktime = converter.to_bytes(worktime);
			_worktime=stof(f_worktime);
			_sum_worktime+=_worktime;
			break;		
		}
		else
		{
			cout << "��ʽ����ȷ,����������" << endl;
			system("pause");
		}

	}while (1);

	//��ʱ��
	time_t now = time(nullptr);			
	tm* timePtr = localtime(&now);		
	stringstream Strstream;
	Strstream << put_time(timePtr, "ʱ��:%Y-%m-%d %H:%M:%S");
	string _time = Strstream.str();

	//���
	attendance new_attendance(_ID,_time,_frequency,_worktime,_sum_worktime);
	attendance_vector.push_back(new_attendance);

	cout << "�򿨳ɹ���"<<endl;
	cout << "����ʱ��:" << _worktime << "h" << endl;
	cout << "��" << _time << endl;

	system("pause");
	system("cls");
	
}

void attendance::Show_Attendance()
{
	wstring id;
	if (attendance_vector.size() == 0)
	{
		cout << "Ŀǰ�޶�Ա������Ϣ������ӡ�" << endl;
		system("pause");
		system("cls");
	}else
	{
		do{
			cout << "\n��������Ҫ�鿴������Ϣ��Ա��ѧ��" <<endl;
			getline(wcin, id);
			id.erase(remove_if(id.begin(), id.end(), ::iswspace), id.end());		
			if (id.length() == 11 && all_of(id.begin(), id.end(), ::isdigit))
			{		
				cout << "������Ϣ����" << endl;	
				break;		
			}
			else
			{
				cout << "ѧ�Ÿ�ʽ����ȷ,������11λ����" << endl;
				system("pause");
			}
		}while (1);
		//���Ҵ�ѧ��
		int num;
		for(int i = 0; i < attendance_vector.size(); i++)
		{
			if( attendance_vector[i]._ID == id)
			{
				cout << "��" << attendance_vector[i]._time << "  ����ʱ��:" << attendance_vector[i]._worktime << endl;
				num=i;
			}
		}
		cout << "������ʱ��:"<< attendance_vector[num]._sum_worktime << "h" << endl;
		system("pause");
		system("cls");
	}	
}
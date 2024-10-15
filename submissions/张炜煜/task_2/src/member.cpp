#include "member.h"

using namespace std;

// ��ʽ����Ĭ�Ϲ���
member::member(){}
// ���죨����thisָ�룩
member::member(wstring id, wstring name, int year, int month ,int day) :
	_ID(id),
	_name(name),
	_year(year), _month(month), _day(day){}
int number=1;
void member::AddMember()
{	
	wstring ID;
	wstring name;
	wstring year, month,day;

	do{
		cout << "\n������ѧ��: ";
		getline(wcin, ID);
		ID.erase(remove_if(ID.begin(), ID.end(), ::iswspace), ID.end());		
		if (ID.length() == 11 && all_of(ID.begin(), ID.end(), ::isdigit))
		{
			_ID=ID;///////////////
			break;		
		}
		else
		{
			cout << "ѧ�Ÿ�ʽ����ȷ,������11λ���֡�" << endl;
			system("pause");
		}

	}while (1);
	// ������֤
	do 
	{
		cout << "\n�¶�Ա����: ";
		getline(wcin, name);
		name.erase(remove_if(name.begin(), name.end(), ::isspace), name.end());

		if (name.empty())
		{
			cout << "��������Ϊ��,���������롣" << endl;;
			continue;
		}
		else
		{ 
			_name=name;////////////
			break; 
		}

	} while (true);

	// ��������֤
	do {
		cout << "\n������������: ";
		getline(wcin, year);
		year.erase(remove_if(year.begin(), year.end(), ::iswspace), year.end());					

		if (year.length() == 4 && all_of(year.begin(), year.end(), ::isdigit))
		{	
			_year=stoi(year);///////////////
			break;
		}
		else
		{
			cout << "������ݸ�ʽ����,����������" << endl;
		}

	} while (true);

	// ����·���֤
	do {
		cout << "\n����������·�: ";
		getline(wcin, month);
		month.erase(remove_if(month.begin(), month.end(), ::iswspace), month.end());	

		if ((month.length() == 1 || month.length() == 2) && all_of(month.begin(), month.end(), ::isdigit))
		{	
			if (stoi(month) >= 1 && stoi(month) <= 12)
			{
				_month=stoi(month);//////////////
				break;
			} 
			else
			{
				cout << "�����·���ֵ����,������1-12������" << endl;
			}
		}
		else
		{
			cout << "�����·ݸ�ʽ����,����������" << endl;
		}

	} while (true);

	// ���������֤
	do {
		cout << "\n�������������: ";
		getline(wcin, day);
		day.erase(remove_if(day.begin(), day.end(), ::iswspace), day.end());	

		if ((day.length() == 1 || day.length() == 2) && all_of(day.begin(), day.end(), ::isdigit))
		{	
			if (stoi(day) >= 1 && stoi(day) <= 31)
			{
				_day=stoi(day);
				break;
			} 
			else
			{
				cout << "����������ֵ����,������1-31������" << endl;
			}
		}
		else
		{
			cout << "�������ڸ�ʽ����,����������" << endl;
		}

	} while (true);
	member newMember(_ID, _name, _year, _month, _year);
	member_vector.push_back(newMember);
	cout << member_vector.size() << endl;
	cout << "\n��Ϣ��ӳɹ�!" << endl;
	do
	{
		cout << "\n������Ϣ��" << endl;
		FILE* fp = fopen("members.txt","a");
		if(!fp)
		{
			cout << "\n�ļ���ʧ��" << endl;
			
		}else{
			wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
   			string text = converter.to_bytes(name);

			fprintf(fp,"���:%d ѧ��:%llu ����:%s ���ʱ��:%d �� %d �� %d ��\n",number,stoll(ID),text,stoi(year),stoi(month),stoi(day));
			number+=1;
			fclose(fp);
			cout << "\n����ɹ�" << endl;
			break;			
		}
	} while (true);
	
}


// �����Ϣ
void PrintMembers(void)
{	
		ifstream ifs;
		ifs.open("members.txt", ios::in);
		if (!ifs.is_open())
		{
			cout << "�ļ���ʧ��" << endl;
			system("pause");
			return;
		}
		cout << "���¼�Ϊ�ֶ�Ա������Ϣ:" << endl;
		//��ӡ
		string buf;
    	while (getline(ifs,buf))
   		{
        	cout << buf << endl;
    	}
		ifs.close();			
//		system("pause");
//		system("cls");		
}

bool isMember(vector<member>& member_vector, const wstring& input)
{
	for(int i = 0; i < member_vector.size(); i++)
	{
		if( member_vector[i]._ID == input)
		{
			return true;
		}
	}
	return false;
}


// ɾ��:����VectorԪ��ɾ��
void  removeMem(vector<member>& member_vector, const wstring& removeID)
{
	long long id;
	// ɾ��member_vector
	for(auto it = member_vector.begin(); it != member_vector.end();)
	{
		if(it->_ID == to_wstring(id))
		{it = member_vector.erase(it);}
		else{++ it;}
	}
	//ɾ���ļ�
	ifstream ifs("members.txt");
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		return;
	}
	vector<string> lines;
	string line;	
	wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
   	string deleteID = converter.to_bytes(removeID);
	bool flag = false;
	while (getline(ifs, line))
	{
		if (line.find(deleteID) == string::npos)
		{ // ������в�����Ҫɾ�����ַ���
			lines.push_back(line);
		}
		else
		{ //�����������ѱ�־λ��Ϊ��
			flag = true;
		}
	}
	ifs.close();

	// ������������д���ļ�
	ofstream ofs;
	ofs.open("members.txt", ios::trunc);
	if (!ofs.is_open())
	{
		cout << "�޷�������ļ�" << endl;
		return;
	}

	for (vector<string>::iterator it = lines.begin(); it != lines.end(); it++)
	{
		ofs << *it << endl;
	}
	ofs.close();
	if (flag)
	{
		cout << "�����ɹ�" << endl;
		system("pause");
		return;
	}

}

// ɾ��
void member::DeleteMember()
{	

	if (member_vector.size() == 0)
	{
		cout << "Ŀǰ�޶�Ա��Ϣ������ӡ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");		// ���������ڲ鿴

		// ����ƥ���ж�
		do 
		{	
			cout << "\n��˶���ɾ����Ա��ѧ��";
			PrintMembers();
			cout << "\n��������ɾ����Ա��ѧ��(����0�Է��ز˵�):";
			
			wstring removeID;
			getline(wcin, removeID);
			removeID.erase(remove_if(removeID.begin(), removeID.end(), ::iswspace), removeID.end());		// ȥ���ַ����е����пո�
			if(stoll(removeID)==0){
				return;
			}
			if(isMember(member_vector, removeID))
			{
				removeMem(member_vector, removeID);		// ɾ����Ա	
				cout << "ɾ���ɹ�,�����" << endl;
				PrintMembers();
				system("pause");
				system("cls");
				
				return;
				
			}
			else
			{	
				cout << "��Ǹ��������Ķ�Ա��Ϣ�����ڣ��밴��ʾ�������롣" << endl;
				system("pause");
				system("cls");
			}

		} while (true);
	}
}

// �޸�
void member::ChangeMember()
{

	if (member_vector.size() == 0)
	{
		cout << "Ŀǰ�޶�Ա��Ϣ������ӡ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		system("cls");		// ���������ڲ鿴
		// ����ƥ���ж�
		do 
		{	
			PrintMembers();
			cout << "\n���������޸���Ϣ��Ա��ѧ��(����0�Է��ز˵�):";
			
			wstring removeID;
			getline(wcin, removeID);
			removeID.erase(remove_if(removeID.begin(), removeID.end(), ::iswspace), removeID.end());		// ȥ���ַ����е����пո�
			if(stoll(removeID)==0){
				return;
			}
			if(isMember(member_vector, removeID))
			{
				removeMem(member_vector, removeID);		// ɾ����Ա					
				number-=1;
				AddMember();
				system("cls");
				cout << "�޸����,�����" << endl;
				PrintMembers();
				system("pause");
				system("cls");				
				return;
				
			}
			else
			{	
				cout << "��Ǹ��������Ķ�Ա��Ϣ�����ڣ��밴��ʾ�������롣" << endl;
				system("pause");
				system("cls");
			}
		} while (true);		
	}
}
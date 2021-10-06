#include<iostream>
#include<iomanip>
#include<string>
#include<fstream>
using namespace std;

class GV
{
	private: 
		char ht[30];
		int t;
		char bc[15];
		char cn[20];
		float bl;
	public:
		/*
GV (char* ht, int t, char* bc,char* cn,float bl)
		{
		strcpy(this->ht,ht);
		this-> t = t;
		strcpy(this->bc,bc);
		strcpy(this->cn,cn);
		this-> bl = bl;
		}*/
		~GV () {}	
		
		float lcb()
		{
			return bl*610;
		}
		char *bangcap()
			{
			return bc;	
			}  
		friend istream& operator >> (istream& x, GV &gv1);
		friend	ostream& operator << (ostream& y, GV gv1);
		friend bool operator == (GV &a, GV &b);
};
		istream& operator >> (istream& is, GV &gv1)
		{
			fflush(stdin);
			cout<<"Nhap ho ten: ";
			is.getline(gv1.ht,31);
			cout<<"Nhap bang cap: ";
			is.getline(gv1.bc,16);
			cout<<"Nhap chuyen nganh: ";
			is.getline(gv1.cn,21);
			cout<<"Nhap tuoi: ";
			is>>gv1.t;
			cout<<"Nhap bac luong: ";
			is>>gv1.bl;
			return is;
		}
		ostream& operator << (ostream& os, GV gv1)
		{
			os<<setw(31)<<gv1.ht;
  		  	os<<setw(2)<<"|";
  		  	
  		  	os<<setw(6)<<gv1.t;
  		  	os<<setw(2)<<"|";
  		  	
  		  	os<<setw(16)<<gv1.bc;
  		  	os<<setw(2)<<"|";
  		  	
  		  	os<<setw(21)<<gv1.cn;
  		  	os<<setw(2)<<"|";
  		  	
  		  	os<<setw(10)<<gv1.bl;
  		  	os<<setw(2)<<"|"<<endl;
  		  	return os;
		}
		bool operator == (GV& a, GV& b)
		{
			if(strcmpi( a.bangcap(),b.bangcap()) == 0)
				{
				return true;
				}
			else
				return false;
		}
		void sapxep (GV a[], int n)
		{
			for (int i=0;i<n;i++)
			{
				for (int j=i+1;j<n;j++)
				{
					if (strcmpi (a[i].bangcap(),a[j].bangcap()) > 0)
					{
						GV temp = a[i];
						a[i] = a[j];
						a[j] = temp;
					}
				}
				cout<<a[i];
			}
		}
void tieude()
{
			cout<<setw(31)<<"HO_TEN";
  		  	cout<<setw(2)<<"|";
  		  	
  		  	cout<<setw(6)<<"TUOI";
  		  	cout<<setw(2)<<"|";
  		  	
  		  	cout<<setw(16)<<"BANG_CAP";
  		  	cout<<setw(2)<<"|";
  		  	
  		  	cout<<setw(21)<<"CHUYEN_NGANH";
  		  	cout<<setw(2)<<"|";
  		  	
  		  	cout<<setw(10)<<"BAC_LUONG";
  		  	cout<<setw(2)<<"|"<<endl;
}
int main ()
{
	int n;
	cout<<"Nhap so luong giao vien : ";
	cin>>n;
	GV *ngv = new GV[n];
	cout<<"NHAP THONG TIN: "<<endl;
	for (int i=0;i<n;i++)
	{
		cout<<"Nhap thong tin GV thu "<<i+1<<" : "<<endl; 
		cin >> ngv[i];
	}
	cout<<"XUAT THONG TIN: "<<endl;
	tieude();
	for (int i=0;i<n;i++)
	{
		cout << ngv[i];
	}	
	cout<<"SAP XEP NHAN VIEN THEO BANG CAP: "<<endl;
	tieude();
	sapxep(ngv,n);
	return 0;
}
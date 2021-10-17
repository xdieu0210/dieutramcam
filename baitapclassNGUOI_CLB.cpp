#include<iostream>
#include<conio.h>
#include<iomanip>
#include<string>

using namespace std;
class NGUOI
{
	private:
	    string hoten;
	    int tuoi;
	    string nghenghiep;
	    string quoctich;
	public:
   		 NGUOI()
    {
       this->hoten,hoten;
       this->nghenghiep,nghenghiep;
       this->quoctich,quoctich; 
       this->tuoi = tuoi;
    };
    ~NGUOI(){};
    void nhap ()
    {
        fflush(stdin);
        cout<<"Nhap ho va ten: ";
        getline(cin,hoten);
        cout<<"Nhap nghe nghiep: ";
        getline(cin,nghenghiep);
        cout<<"Nhap quoc tich: ";
        getline(cin,quoctich);
        cout<<"Nhap tuoi: ";
        cin>>tuoi;
    }
    string tachten (string hoten)
    { int vt,i,j;
    string a;
    	 for (int i= hoten.length()-1;i>=0;i--)
	    {
    		if(hoten[i]==' ') 
    		{
		    	 vt = i;
		    	 break;
    		}
	    }
    
    for (j= vt + 1 ; j < hoten.length() ; j++)
		{
			a = a + hoten[j];
		}
		return a;
    }
     void xuat ()
    {
        cout<<setw(31)<<hoten;
        cout<<setw(2)<<"|";

        cout<<setw(5)<<tuoi;
        cout<<setw(2)<<"|";

        cout<<setw(15)<<nghenghiep;
        cout<<setw(2)<<"|";

        cout<<setw(15)<<quoctich;
        cout<<setw(2)<<"|"<<endl;
    }
    string gethoten ()
    {
    	return hoten;
    }
    string getquoctich()
    {
    	return quoctich;
    }
    int &gettuoi()
    {
    	return tuoi;
    }
};
void tieude()
    {
        cout<<setw(31)<<"HO_TEN";
        cout<<setw(2)<<"|";

        cout<<setw(5)<<"TUOI";
        cout<<setw(2)<<"|";

        cout<<setw(15)<<"NGHE_NGHIEP";
        cout<<setw(2)<<"|";

        cout<<setw(15)<<"QUOC_TICH";
        cout<<setw(2)<<"|"<<endl;
    }
    
int main ()
{
    int n;
    cout<<"Nhap so nguoi: ";
    cin>>n;

    NGUOI *ng = new NGUOI[n];
    cout<<"NHAP_THONG_TIN"<<endl;
    for (int i=0;i<n;i++)
    {
    	cout<<"\nNhap thong tin nguoi thu "<<i+1<<" : "<<endl;
    	ng[i].nhap();
    }
    cout<<"XUAT_THONG_TIN"<<endl;
    tieude();
    for (int i=0;i<n;i++)
    {
    	ng[i].xuat();	
    }
	 
    cout<<"SAP_XEP_TEN_TANG_DAN"<<endl;
    tieude();
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if(ng[i].tachten(ng[i].gethoten()) > ng[j].tachten(ng[j].gethoten()))
            {
                NGUOI temp = ng[i];
                ng[i] = ng[j];
                ng[j] = temp;
            }
        }
        ng[i].xuat();
    }
    cout<<"XOA_QUOC_TICH_VIET_NAM"<<endl;
    tieude();
    for (int i=0;i<n;i++)
    {
    	if (ng[i].getquoctich() != "Viet Nam" )
    	{
	    	ng[i].xuat();
	    }
    }
    
    cout<<"SAP_XEP_GIAM_DAN_TUOI"<<endl; //khong dung trung gian  
    tieude();
    for (int i=1;i<n;i++) 	//insertion sort 
    {NGUOI x = ng[i]; int pos = i-1;
    	while ((pos >= 0) && (ng[pos].gettuoi() < x.gettuoi()))
    	{
	    	ng[pos + 1] = ng[pos];
	    	pos--;
	    }
	    ng[pos+1] = x;
    }
    for (int i=0;i<n;i++)
    {
    	ng[i].xuat();
    }
        
}


#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool f1,f2,f3,f4;
	f1=f2=f3=f4=0;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	f1=(a==c);
	if(f1==0)
	{
		cout<<"0000"<<endl;
	}
	else{
		string q1=b.substr(0,2);
		string q2=d.substr(0,2);
		f2=(q1==q2);
		if(f2==0)
			cout<<"1000"<<endl;
		else{
			char ch1=b.back();
			char ch2=d.back();
			int s1=ch1-'A',s2=ch2-'A';
			if((s1>=0&&s1<=2)&&(s2>=0&&s2<=2))
				f3=1;
			if((s1>=3&&s1<=4)&&(s2>=3&&s2<=4))
				f3=1;
			if((s1==2&&s2==3)||(s1==3&&s2==2))
				f4=0;
			else
				f4=(abs(s1-s2)==1);
			cout<<f1<<f2<<f3<<f4<<endl;
		}
	}
	return 0;
}

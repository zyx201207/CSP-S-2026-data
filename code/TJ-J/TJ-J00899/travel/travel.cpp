#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int C1=0,S1=0,C2=0,S2=0,cnt=10;
	char a1,a2;
	for(int i=0;i<=1;i++)
	{
		C1+=(c1[i]-'0')*cnt;
		C2+=(c2[i]-'0')*cnt;
		S1+=(s1[i]-'0')*cnt;
		S2+=(s2[i]-'0')*cnt;
		cnt/=10;
	}
	a1=s1[2];
	a2=s2[2];
	 if(C1==C2)
	 {
	 	cout<<"1"; 
	 	if(S1==S2)
	 	{
	 		cout<<"1";
	 		if((a1<='C'&&a2<='C')||(a1>='D'&&a2>='D'))
	 		{
	 			cout<<"1";
	 			if(a1==a2+1||a2==a1+1)
	 				cout<<"1";
	 			else
	 				cout<<"0";
			 }
			 else
			 	cout<<"00";
		 }
		 else
		 	cout<<"000";
	 }
	 else
	 	cout<<"0000";
	
	
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	 freopen("travel.in","r",stdin);
	 freopen("travel.out","w",stdout);
	 int c1,c2,s1,s2;
	 char ss1,ss2;
	 cin>>c1>>s1>>ss1>>c2>>s2>>ss2;
	 if(c1==c2)
	 {
		 if(s1==s2)
		 {
			 if(ss1+0<='C'+0&&ss2+0<='C'+0)
			 {
				 if(ss1+0-ss2+0==1||ss2+0-ss1+0==1)
				 {
					 cout<<"1111";
				 }
				 else cout<<"1110";
			 }
			 else if(ss1+0>'C'+0&&ss2+0>'C'+0)
			 {
				 if(ss1+0-ss2+0==1||ss2+0-ss1+0==1)
				 {
					 cout<<"1111";
				 }
				 else cout<<"1110";
			 }
			 else cout<<"1100";
		 }
		 else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}

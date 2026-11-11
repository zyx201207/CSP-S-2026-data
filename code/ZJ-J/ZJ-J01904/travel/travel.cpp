#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f[6]={0,0,0,1,1,1};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000";
	else{
		int t1=s1[0]*10+s1[1],t2=s2[0]*10+s2[1],a1=s1[2]-'A',a2=s2[2]-'A';
		if(t1!=t2)cout<<"1000";
		else{
			if(f[a1]!=f[a2])cout<<"1100";
			else{
				if((a1==0&&a2==2)||a1==2&&a2==0)cout<<"1110";
				else cout<<"1111";
			}
		}
	}
	return 0;
}

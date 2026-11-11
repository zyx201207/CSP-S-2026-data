#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	int n1=(s2[0]-'0')*10+s2[1]-'0',n2=(s4[0]-'0')*10+s4[1]-'0';
	if(n1==n2){
		cout<<"1";
		char a1=s2[2],a2=s4[2],ch1=min(a1,a2),ch2=max(a1,a2);
		if((ch1=='A'&&(ch2=='B'||ch2=='C'))||(ch1=='B'&&ch2=='C')||(ch1=='D'&&ch2=='F')){
			cout<<"1";
			int s1=a1-'A',s2=a2-'A';
			if(s1+1==s2){
				cout<<"1";
				return 0;
			}else{
				cout<<"0";
				return 0;
			}
		}else{
			cout<<"00";
			return 0;
		}
	}
	else{
		cout<<"000";
	}
	return 0;
}

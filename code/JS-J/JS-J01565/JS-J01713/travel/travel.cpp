#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else{
		cout<<1;
		string m1="",m2="";
		for(int i=0;i<=1;i++) m1+=s1[i],m2+=s2[i];
		if(m1==m2) cout<<1;
		else cout<<0;
			int a=0,b=0;
			for(int i=0;i<=1;i++){
			a*=10;
			a+=(int)(s1[i]-'0');
			b*=10;
			b+=(int)(s2[i]-'0');
			}
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
				if(m1==m2) cout<<1;
				else cout<<0;
				if(a-1==b&&s1[2]==s2[2]) cout<<1;
				else if(a+1==b&&s1[2]==s2[2]) cout<<1;
				else if(a==b&&((int)(s1[2])-1==(int)s2[2]||(int)(s2[2]-1)==(int)s1[2])) cout<<1;
				else cout<<0;
			}
			else if((s1[2]=='D'||s2[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
				if(m1==m2) cout<<1;
				else cout<<0;
				if(a-1==b&&s1[2]==s2[2]) cout<<1;
				else if(a+1==b&&s1[2]==s2[2]) cout<<1;
				else if(a==b&&((int)(s1[2])-2==(int)s2[2]||(int)(s2[2]-2)==(int)s1[2])) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
	}
	return 0;
}

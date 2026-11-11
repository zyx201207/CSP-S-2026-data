#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
		int m=c1[0]-'0';
		int k=c1[1]-'0';
		int x=c2[0]-'0';
		int y=c2[1]-'0';
		if(m==x&&k==y)
		{
			cout<<1;
		}
		else{
			cout<<0;
		}
		int e=s1[0]-'0';
		int f=s2[0]-'0';
		int a=s1[1]-'0';
		int b=s2[1]-'0';
		int c=s1[2]-'A'+1;
		int d=s2[2]-'A'+1;
		if(a==b&&e==f)
			cout<<1;
		else cout<<0;
		if(c+1==4&&d==4){
			cout<<0;
			cout<<0;
		}
		else {
			cout<<1;
			if(c+1==d|c-1==d)
			cout<<1;
			else cout<<0;
	}
	return 0;
}

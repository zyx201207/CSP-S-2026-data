#include<bits/stdc++.h>
using namespace std;
int n,m;
string s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s1>>m>>s2;
	s1=' '+s1;
	s2=' '+s2;
	int p1=0,p2=0;
	for(int i=1;i<=2;i++){
		p1=p1*10+(s1[i]-'0');
		p2=p2*10+(s2[i]-'0');
	}
	bool f1=(n==m),f2=(p1==p2),f3=(s1[3]<='C'&&s2[3]<='C')||(s1[3]>='D'&&s2[3]>='D'),f4=((s1[3]==s2[3]+1)||(s1[3]==s2[3]-1));
	cout<<f1<<(f1&&f2)<<(f1&&f2&&f3)<<(f1&&f2&&f3&&f4);
	return 0;	
}

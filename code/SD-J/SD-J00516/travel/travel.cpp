#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn 200003
int a,b,c,d,i,j,k,m,n,ans,sum,tot,cnt,l,r,p,x,y,t,dis[maxn];
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travrl.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3)cout<<++l;
	else cout<<0;
	if(s2[0]==s4[0]&&s2[1]==s4[1]&&l)cout<<++r;
	else cout<<0;
	if(r&&l&&(s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C')||(s2[2]>='D'&&s2[2]<='F'&&s4[2]>='D'&&s4[2]<='F')){
		cout<<++cnt;
	}
	else cout<<0;
	if(l&&r&&cnt&&abs(s2[2]-s4[2])==1)cout<<1;
	else cout<<0;
	cout<<endl;
	return 0;
}

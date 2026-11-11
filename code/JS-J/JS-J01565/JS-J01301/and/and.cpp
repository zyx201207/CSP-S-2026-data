#include<bits/stdc++.h>
using namespace std;
int n,m,ans,a[200010];
long long read(){
	long long s=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
	return s;
}
int _1(int x){
	int y=0;
	while(x){
		y+=x%2;
		x/=2;
	}
	return y;
}
bool cmp(int u,int v){
	if(_1(u)!=_1(v))return _1(u)>_1(v);
	else return u>v;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1,cmp);
	ans=a[1];
	for(int i=2;i<=m;i++)ans&=a[i];
	cout<<ans;
	return 0;
}

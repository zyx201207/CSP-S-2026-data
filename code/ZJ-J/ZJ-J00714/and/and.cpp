#include<bits/stdc++.h>
using namespace std;
int n,m,ma;
long long a[200005];
bool cmp(long long x,long long y){
	long long tmp=1;
	long long xg=0,yg=0;
	while(x||y){
		xg+=tmp*(x&1?1:-1),x>>=1;
		yg+=tmp*(y&1?1:-1),y>>=1;
		tmp<<=1;
	}
	return xg>yg;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n,cmp);
	long long ans=a[1];
	bool ok=0;
	for(int i=2,k=1;i<=n;i++){
		if(k==m){ok=1;break;}
		if((ans&a[i])==0)ans=a[i],k=1;
		else ans&=a[i],k++;
	}
	cout<<(ok?ans:0);
	return 0;
}

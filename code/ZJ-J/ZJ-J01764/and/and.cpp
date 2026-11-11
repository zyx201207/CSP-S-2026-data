#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans,ch[40],b[200005],cnt;
int aanndd(int x[]){
	int sum=0,ii=1,t=0;
	for(int i=1;i<=m;i++)t=max(t,x[i]);
	while(t>=ch[ii])ii++;
	ii--;
	while(ii>0){
		int f=0;
		for(int i=1;i<=m;i++){
			if(x[i]/ch[ii]!=1){
				f=1;
				break;
			}x[i]%=ch[ii];
		}
		if(f==0)sum+=ch[ii];
		ii--;
	}return sum;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	ch[1]=1;
	ans=a[n];
	for(int i=2;i<=31;i++)ch[i]=ch[i-1]*2;
	for(int i=n;i>=n-m+1;i--)b[++cnt]=a[i];
	ans=aanndd(b);
	cout<<ans;
	return 0;
}
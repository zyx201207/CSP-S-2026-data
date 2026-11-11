#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,i,a[200010],f[40],cnt,t,b[200010],j,ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	f[0]=1;
	for(j=1;j<=30;j++)f[j]=f[j-1]*2;
	for(i=30;i>=0;i--){
		cnt=0;t=0;
		for(j=1;j<=n;j++)
			if((a[j]&f[i])){
				cnt++;
				t++;
				b[t]=a[j];
			}
		if(cnt>=m){
			for(j=1;j<=t;j++)
				a[j]=b[j];
			n=t;
			ans+=f[i];
		}
	}
	cout<<ans;
	return 0;
}


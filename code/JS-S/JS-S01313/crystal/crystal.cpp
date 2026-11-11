#include<bits/stdc++.h>
using namespace std;
const int N=6e5;
typedef long long LL;
typedef unsigned long long ULL;
LL a[N];
int n,ans,s;
ULL c,t,m;
bool b=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>1;i--)a[i]-=a[i-1];
	for(int i=2;i<n;i++)if(a[i]!=a[i+1])b=false;
	if(b){
		int t=a[2];
		if(t==0){
			cout<<n;
			return 0;
		}
		int cc=1;
		while(1ULL*cc*(cc+1)*t/2<=m)cc++;
		cout<<min(n,cc);
		return 0;
	}
	for(int i=1;i<=n;i++){
		int cnt=1;
		c=0;
		while(i+cnt<=n){
			if(a[i+cnt]==0){
				cnt++;
				continue;
			}
			t=1LL*cnt*a[i+cnt];
			if(m-c<t)break;
			c+=t;
			cnt++;
		}
		if(cnt>ans)ans=cnt;
		if(ans==n)break;
	}
	cout<<ans;
	return 0;
}

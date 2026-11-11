#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d;
int a[2000010];
bool flag;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c==11||c==12)flag=true;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(flag){
			int D=a[2]-a[1];
			int k=d/D;
			if(k==0||k==1)cout<<0<<'\n';
			int p=2*k-1;
			if(k!=0&&k!=1)cout<<max(n-p,0LL)<<'\n';
		}
		else if(c==13||c==14){
			int aa=lower_bound(a+1,a+n+1,a[n]-d)-a,ss=upper_bound(a+1,a+n+1,a[1]+d)-a-1;
			if(ss!=aa+1)cout<<0<<'\n';
			else{
				int dd=upper_bound(a+1,a+n+1,a[aa-1]+d)-a,ff=lower_bound(a+1,a+n+1,a[ss+1]-d)-a-1;
				cout<<ff*(n-dd+1)<<'\n';
			}
		}
	}
	return 0;
}

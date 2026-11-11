#include <bits/stdc++.h>
using namespace std;
int c,t;
const int N=2e6+10;
long long a[N],n,d;
void workA(){
	if(d<2*(a[2]-a[1])||n<2*d/(a[2]-a[1])){
		cout<<0<<endl;
	}else{
		cout<<(n-2*d/(a[2]-a[1])+1)<<endl;
	}
}
void workB(){
	int ans=0;
	for(int i=1;i<=n;i++){
		int k1=lower_bound(a+1,a+n+1,a[i]+d)-a-1;
		int k2=lower_bound(a+1,a+n+1,a[k1-1]+d)-a-1;
		if(k2==n){
			ans+=n-k1+1;
		}else{
			ans+=k2-k1+1;
		}
	}
	cout<<ans<<endl;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12||c==0){
		while(t--){
			for(int i=1;i<=n;i++) a[i]=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			workA();
		}
	}
	if(c==13||c==14){
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			workB();
		}
	}
	return 0;
}
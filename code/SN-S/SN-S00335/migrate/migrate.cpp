//姓名：张邦寒 学校：西安交通大学附属中学 准考证号：SN-S00335 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,T,n,d,a[2001000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		bool ok=true;
		for(int i=2;i<=n;i++){
			if(i==2) continue;
			if(a[i-1]-a[i-2]!=a[i]-a[i-1]){
				ok=false;
				break;
			}
		}
		if(ok){
			ll gc=a[2]-a[1];
			if(d>=2*gc&&d<3*gc){
				cout<<ll((a[n]-a[1])/gc-1ll)<<"\n";
			}else if(d<2*gc){
				cout<<"0\n";
			}else{
				cout<<ll((a[n]-a[1])/gc-1ll)<<"\n";
			}
			continue;
		}
	}
	return 0;
}


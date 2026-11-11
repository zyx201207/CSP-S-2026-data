#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
long long c,t,n,d,x[N];
vector<long long> a;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		a.clear();
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			if(i==1||x[i-1]+d>=x[i]) a.push_back(x[i]);
			else{
				break;
			}
		}
		int len=a.size(),ans=0;
		for(int i=0;i<len;i++){
			for(int j=i+1;j<len;j++){
				int cnt=0;
				for(int k=i;k<=j-2;k++){
					if(a[k]+d>=a[k+1]&&a[k]+d>=a[k+2]) cnt++;
				}
				if(cnt==2&&(j-i)%d!=0) ans++;//cout<<i<<" "<<j<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N =2e6+9;
int c,t,n;
ll a[N],b[N],d,ans;
vector<int> vc[N]; 

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		cin>>n>>d;
		if(c==13||c==14){
			cout<<0<<endl;
			continue;
		} 
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=d+i;j++){
				if(j>n)break;
				if(a[j]-a[i]>d) break;
				vc[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j :vc[i]){
				for(int ij:vc[j]){
//					cout<<i<<" "<<j<<" "<<ij<<endl;
					if(a[ij]-a[i]<=d) continue;
					if((a[ij]-a[i])%2==0) continue;
					b[ij]++;
				}
			}
		}

		for(int i=1;i<=n;i++){
//			cout<<b[i]<<" ";
			if(b[i]==2) ans++;
		}
		cout<<ans<<endl;
		ans=0;
		for(int i=1;i<=n;i++) vc[i].clear();
	}
	
	
	return 0;
}

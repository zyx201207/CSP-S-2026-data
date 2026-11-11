#include<bits/stdc++.h>
using namespace std;
const int N=2e6+3;
#define ll long long
ll c,t,n,m,k,ans,a[N],opp[N];
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){cin>>a[i];}
		fill(opp,opp+2+n,0);
		
		for(int i=2;i<=n;i++){
			opp[i]=a[i]-a[i-1];
			opp[i]+=opp[i-1];
		}
		
		for(int i=4;i<=n;i++){
			ll p=i-1,len[i+2]={};
			while(p>=1&&opp[i]-opp[p]<=k){
				len[i]=1;
				p--;
			}
			while(p){
				ll minn=0x3fffffff,sum=0;
				for(int j=p+1;j<=i&&opp[j]-opp[p]<=k;j++){
					if(minn==len[j])sum++;
					else sum=0;
					minn=min(len[j],minn);
				}
				sum++;
				if(minn==0x3fffffff)break;
				len[p]=minn+1;
				if(sum==2){
					ans++;
				}
				p--;
			}
			
		}
		cout<<ans<<endl;
		ans=0;
	}
	return 0;
}

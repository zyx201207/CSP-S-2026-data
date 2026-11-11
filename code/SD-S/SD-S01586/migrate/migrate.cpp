#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10;
int n,m,a[N],c,t,d,b[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;++c;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i!=1)b[i]=((a[i]-a[i-1]>d)?c:0);
		}ll ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				int cnt=0;
				if(a[j]-a[i]>=2*d||a[j]-a[i]<=d)continue;
				for(int k=i;k<=j;k++){
					if(b[k]==c)break;
					if((a[k]-a[i])<=d&&(a[j]-a[k])<=d)cnt++;
					if(cnt>2)break;
				}if(cnt==2)ans++;
			}
		}cout<<ans<<"\n";
	}
	
	
	
	return 0;
} 

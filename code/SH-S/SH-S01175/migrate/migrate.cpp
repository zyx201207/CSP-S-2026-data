#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const ll maxn=1e5+5;
const ll ml=505;

struct q{
	ll l,r;
};
q qu[maxn];
ll c,t;
ll n,d,a[maxn],dd[maxn],l[maxn],r[maxn],skp[maxn],qzh[maxn],uv[maxn];

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>c>>t;
    while(t--){
    	for(int i=1;i<=n;i++) skp[i]=0;
    	ll ans=0;
    	for(int i=1;i<=n;i++){
    		qzh[i]=0;
		}
    	cin>>n>>d;
    	for(int i=1;i<=n;i++){
    		cin>>a[i];
    		if(i>=2) dd[i]=a[i]-a[i-1];
    		if(dd[i]>d) uv[i]=1;
		}
		ll cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d&&j-i!=1){
					qu[++cnt]={i,j};
					for(int k=i+1;k<=j-1;k++){
						skp[k]++;
						//cout<<k<<endl;
					}
					//cout<<i<<" "<<j<<endl;
				}
			}
		}
		for(int i=1;i<=n;i++){
			qzh[i]=skp[i]+qzh[i-1];
			//cout<<qzh[i]<<" ";
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				if(qzh[j-1]-qzh[i]==2&&j-i-1!=1&&!uv[j]) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

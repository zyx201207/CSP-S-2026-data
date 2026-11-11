#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5009;
int c,t;
ll n,d,far_reach[N],a[N],minstep[N][N],num[N][N],ans=0;
void solve(int start_n,int end_n){
	int dt=start_n-1,len=end_n-start_n+1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			minstep[i][j]=0,num[i][j]=0;
	for(ll i=1;i<len;i++)
			for(ll j=1;j<=len-i+1;j++){
				if(far_reach[j+dt]>=j+i) minstep[j][j+i]=1;
				else minstep[j][j+i]=1+minstep[far_reach[j+dt]][j+i];
			}
	for(ll i=1;i<len;i++)
		for(ll j=1;j<=len-i+1;j++){
			if(far_reach[j+dt]>=j+i) num[j][j+i]=1;
			else{
				for(int k=j+1;k<=far_reach[j+dt];k++)
					if(minstep[j][k]+minstep[k][j+i]==minstep[j][j+i]){
						num[j][j+i]+=num[j][k]*num[k][j+i];
						if(num[j][j+i]>2) break;
					}
				if(num[j][j+i]==2) ans++;
			}
		}
	return ;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	if(c<=10&&c>=13){
		for(int csd=1;csd<=t;csd++){
			ans=0;
			cin>>n>>d;
			for(ll i=1;i<=n;i++){
				cin>>a[i];
				far_reach[i]=i;
			}
			for(ll i=n;i>=2;i--){
				for(ll j=i-1;j>=1;j--){
					if(a[i]-a[j]<=d) far_reach[j]=max(far_reach[j],i);
					else break;
				}
				if(far_reach[1]!=1) break;
			}
			ll last_end=1;
			for(ll i=1;i<=n;i++)
				if(far_reach[i]==i){
					if(i-last_end>=3)
						solve(last_end,i);
					last_end=i+1;
				}
			cout<<ans<<endl;
		}
		return 0;
	}
	else if(c==11||c==12){
		for(int csd=1;csd<=t;csd++){
			ans=0;
			cin>>n>>d;
			ll k1,k2,k3;
			cin>>k1>>k2;
			for(ll i=3;i<=n;i++) cin>>k3;
			ll cha=k2-k1;
			ll k=ceil(d*1.00/cha);
			k3=k1+(n-1)*cha;
			if(d<=cha||d>=k3-k1) ans=0;
			else ans=n-k*2+1;
			cout<<ans<<endl;
		}
	}
}


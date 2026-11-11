#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,L[N],R[N],x[N],dl[N],dr[N];
void solve(){
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>x[i];
	for(int i=1;i<=n;i++)dl[i]=dr[i]=0;
	int r=n;
	for(int i=n;i>=1;i--){
		while(x[r]-x[i]>d)r--;
		R[i]=r,dr[r]++;
	}
	int l=1;
	for(int i=1;i<=n;i++){
		while(x[i]-x[l]>d)l++;
		L[i]=l,dl[l]++;
	}
	for(int i=2;i<n-1;i++){
		if(R[i]==i+1||L[i+1]==i)continue;
		int k1=i,k2=i+1;
		int n1=0,n2=0,z1=k1,z2=k2;
		while(k2!=R[k2]){
			k2=R[k2];
			n1+=dl[z1];
			if(L[k2]!=z1)break;
			z1=k2;
		}
		while(k1!=L[k1]){
			k1=L[k1];
			n2+=dr[z2]; 
			if(R[k1]!=z2)break;
			z2=k1;
		}
//		cout<<n1<<" "<<n2<<endl;
		ans+=n1*n2;
	}
	cout<<ans<<"\n";
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	while(t--)solve();
	return 0;
}

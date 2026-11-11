#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
const int N=1e6+5;
const int mod=1e9+7;
const double eps=1e-6;
int n,m,a[N],b[N],l[N],r[N],sum[N],c[N],q[N];
vector<int> g[N]; 
void subbA(){
	int cnt=1,A=0;
	for(int i=2;i<=n;i++){
		if(a[i]==a[i-1])cnt++;
		else{
			sum[A]=sum[A-1]+cnt;
			cnt=1;
			cout<<sum[A]<<' ';
			A++;
		}
	}
	if(cnt>0)cout<<sum[A-1]+cnt;
	cout<<'\n';
	return ;
}
void solve(){
	cin>>n>>m;
	bool subA=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(b[a[i]]>0){
			l[i]=b[a[i]];
			r[l[i]]=i;
			b[a[i]]=i;
		}
		if(a[i]<a[i-1])subA=0;
	}
	if(m==1){
		cout<<n<<'\n';
		return ;
	}
	if(subA){subbA();return ;} 
	for(int i=1;i<=n;i++){
		int t=0;
		for(int j=i;j<=n;j++){
			q[++t]=a[j];
			for(int k=t-1;k>=1;k--){
				if(a[j]==q[k]){
					t=k;
					break;
				}
			}
//			for(int k=1;k<=t;k++)cout<<q[k]<<' ';
//			cout<<'\n';
		}
		for(int j=1;j<=t;j++)c[q[j]]++;
//		cout<<'\n';
	} 
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
}
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
//	freopen("card1.in","r",stdin);
//	freopen("card.out","w",stdout);
	int T=1;
//	cin>>T;
	while(T--)solve();
	return 0;
}


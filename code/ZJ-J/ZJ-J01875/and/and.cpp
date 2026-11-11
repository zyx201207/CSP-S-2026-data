#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=4e5+5;
ll num[N];
ll cf[N];
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cf[0]=1;
	for(int i=1;i<=30;i++){
		cf[i]=2*cf[i-1];
	}ll n,m;
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%lld",&num[i]);
	}ll ans=0;
	sort(num,num+n,cmp);
	for(int i=30;i>=0;i--){
		if(ll(num[m-1]&cf[i])==0){
			for(int j=0;j<m;j++){
				num[j]=ll(num[j]&(cf[i]-1));
			}sort(num,num+n,cmp);
		}else{
			ans+=cf[i];
			for(int j=m-1;j<=n;j++){
				if(ll(num[j]&cf[i])==0) n=j-1;
			}
		}
	}cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m,ans=0,max=-1,k=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i+1]-a[i];
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i;j<=n-1;j++){
			if(ans+b[j]>m){
				break;
			}
			ans+=b[j];
			k++;
		}
		if(max<k+1){
			max=k+1;
		}
		ans=0;
		k=0;
	}
	cout<<max;
	return 0;
}

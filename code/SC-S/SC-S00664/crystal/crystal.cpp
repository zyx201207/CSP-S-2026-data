#include<bits/stdc++.h>
using namespace std;
using ll = long long;     
const int N=1e6+5;

int a[N],b[N],c[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin.tie(0)->sync_with_stdio(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[i]=1;
		c[i]=a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[j]<=a[i]+m){
				b[i]++;
				c[i]+=a[j];
			}else{
				break;
			}
		}
	}
	int ans=0; 
	for(int i=1;i<=n;i++){
		if(b[i]>ans&&a[i+b[i]-1]*b[i]<=c[i]+m){
			ans=b[i];
		}
	}
	cout<<ans;
	return 0;
}
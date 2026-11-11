#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int j=1,ans=0;
int a[N],b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int k=a[1];
	for(int i=1;i<=n;i++){
		if(a[i]>k)b[i]=b[i-1]+(i-j)*(a[i]-k);
		else b[i]=b[i-1]+k-a[i];
		k=max(k,a[i]);
		if(b[i]>m){
			while(b[i]>m){
				b[i]=b[i]+a[j]-a[i];
				j++;
			}
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],b[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	unsigned long long  maxn=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>maxn){
			maxn=a[i];
		}
		if(i==1){
			b[i]=a[i];
		}
		else{
			b[i]=a[i]&b[i-1];
		}
	}
	if(m==1) cout<<maxn;
	if(m==n) cout<<b[n];
	long long ans=-1;
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=n;j>i;j--){
				int w=a[i]&a[j];
				if(ans<w){
					ans=w;
				}
			}
		}
		cout<<ans;
	}
	return 0; 
}

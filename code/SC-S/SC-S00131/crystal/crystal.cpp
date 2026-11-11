#include<bits/stdc++.h> 
using namespace std;
const int N=500005;
int a[N],n,ans[N];
int long long m,use=0;
void szbj(int b[N]){
	for(int i=1;i<=n;i++){
		for(int j=i,z;j>=1;j--){
			if(b[i]<b[i-1]){
			z=b[i];
			b[i]=b[i-1];
			b[i-1]=z;
			}
		}
	}
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	szbj(a);
	for(int i=1;i<=n;i++){
		ans[i]=1;
		for(int j=i;j>1;j--){
			use+=a[j]-a[j-1];
			a[j-1]=a[j];
			if(use<=m){
				ans[i]++;
			}
		}
	}
	szbj(ans);
	cout<<ans[n];
	return 0;
}
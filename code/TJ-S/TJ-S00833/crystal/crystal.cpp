#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,k;
long long a[1000005];
int ans=-1,maxx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		k=m;
		maxx=0;
		for(int j=i;j>=1;j--){
			if(a[i]==a[j]){
				maxx++;
				continue;
			}
			k=k-a[i]+a[j];
			maxx++;
			if(k==0) break;
			if(k<0){
				maxx--;
				break;
			}
		}
		ans=max(ans,maxx);
	}
	cout<<ans;
}

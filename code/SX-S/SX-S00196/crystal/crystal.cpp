#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],b[100005],c[100005],sum,ans,maxx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);

	for(int i=1;i<=n;i++){
		sum=0;
		ans=0;
		for(int j=i;j>=1;j--){

			if(ans+a[i]-a[j]<m){
				ans+=a[i]-a[j];
				sum++;
			}else if(ans+a[i]-a[j]==m){
				sum++;
				break;
			}else{
				break;
			}
		}
		maxx=max(sum,maxx);
	}
	cout<<maxx;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],f[500005],ans,sum,j;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		//cout<<a[i]<<"  \n";
		b[i]=a[i+1]-a[i];
	}j=1;
	for(int i=1;i<n;i++){
		sum=b[i]*(i-j+1)+sum;
		if(sum>m){
			ans=max(ans,i-j+1);
			while(sum>m){
				sum-=(a[i+1]-a[j]);j++;
			}
		}
	}cout<<ans;//true
	return 0;
}

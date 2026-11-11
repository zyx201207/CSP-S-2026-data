#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500100],sum,ans,ans2;
int main (){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;++i){
		cin>>a[i];
	}
	sort(a+1,a+m+1);
	for(int i=m;i>=1;--i){
		ans=1;
		sum=0;
		for(int j=i-1;j>=1;--j){
			if(sum+a[i]-a[j]>n){
				break;
			}
			sum+=a[i]-a[j];
			ans+=1;	
		}
		ans2=max(ans2,ans);
	}
	cout<<ans2;
	return 0;
} 

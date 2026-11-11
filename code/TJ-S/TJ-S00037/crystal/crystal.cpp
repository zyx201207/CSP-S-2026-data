#include<bits/stdc++.h>
using namespace std;
long long m,n,ans=-1;
long long arr[500005];
struct Node{
	long long num;
	long long pay;
}nrr[500005];
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>arr[i];
	}
	sort(arr+1,arr+n+1,cmp);
	for(long long i=1;i<=n;i++){
		nrr[i].num=nrr[i-1].num+1;
		nrr[i].pay=nrr[i-1].pay+(arr[i]-arr[i-1])*(nrr[i-1].num);
		if(nrr[i].pay>m){
		
			ans=max(nrr[i-1].num,ans);
			for(long long j=1;j<=i;j++){
				nrr[i].num-=1;
				nrr[i].pay-=(arr[i]-arr[j]);
				if(nrr[i].pay<=m){
					ans=max(ans,nrr[i].num);
		
				}
			}
		}
	}
	if(ans==-1){
		ans=nrr[n].num;
	}
	cout<<ans;

	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

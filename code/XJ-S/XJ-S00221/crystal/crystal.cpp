#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],d[500005],cst[500005],dd[500005],cost[50005],sum[50005];
bool f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;int ans=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}sort(a,a+n);
	cst[0]=0;dd[0]=0;
	for(int i=1;i<n;i++){
		d[i]=a[i]-a[i-1];	
	}d[0]=a[0];
	for(int i=0;i<=n;i++){
		
		dd[i]=d[i]*(i);
	}
	for(int i=1;i<=n;i++){
		cst[i]=cst[i-1]+dd[i];
	}for(int i=1;i<n;i++){
		if(d[i]==d[i+1])f=1;
		else f=0;
	}if(f){
		for(long long i=1;i<=m;i++){
			if(i*(i+1)/2*d[i]>m){
				cout<<i-1;
				return 0;
			}
		}
	}for(int i=1;i<=n;i++){
		if(cst[i]>m){
			ans=max(ans,i-1);
			break;
		}
	}
	for(int i=0;i<n;i++){
		
		for(int j=i+1;j<n;j++){
			if(j==i+1)cost[j]=0;
			if(j==i+2)cost[j]=d[j];
			else {
				cost[j]=(j-i)*a[j]-(sum[j]-sum[i]);
			}
			if(m<cost[j]){
				ans=max(j-i,ans);
				break;
			}
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

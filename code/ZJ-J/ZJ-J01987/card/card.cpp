#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=500100;
int n,m,a[N],w[N],c[N],p[N],ans[N],sum=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=1;
	}
	for(int i=n;i>=1;i--){
		w[i]=p[a[i]];
		p[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(w[i]!=0){
			c[w[i]]+=sum+c[i];
			c[i]-=sum+c[i];
		}else{
			sum+=c[i];	
		}
	}
	sum=0;
	for(int i=1;i<=n;i++) {
		sum+=c[i];
		ans[a[i]]=max(sum,ans[a[i]]);
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

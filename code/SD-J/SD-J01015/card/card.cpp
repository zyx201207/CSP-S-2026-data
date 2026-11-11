#include<bits/stdc++.h>
using namespace std;
int a[500005],c[300005],cnt[5005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,f=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1])f=0;
	}
	if(f){
		long long ans=0;
		for(int i=1;i<=n;i++){
			c[a[i]]++;
		}
		for(int i=1;i<=m;i++){
			ans+=c[i];
			cout<<ans<<" ";
		}
	}	
	if(n>5000){
		for(int i=1;i<=m;i++)cout<<n<<" ";
	}
	if(n<=500){
		for(int i=0;i<n;i++){
			for(int j=1;j<=505;j++){
				c[j]=0;
			}
			for(int j=i+1;j<=n;j++){
				if(c[a[j]]!=0){
					for(int k=c[a[j]];k<=j;k++){
						c[a[k]]=0;
					}
				}
				c[a[j]]=j;
			}
			for(int j=1;j<=m;j++){
				if(c[j]!=0)cnt[j]++;
			}
		}
		for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	}
		
	return 0;
}

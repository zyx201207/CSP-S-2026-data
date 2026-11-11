#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long
int n,cnt,a[N],sum[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i]; 
	}
	for(int i=1;i<=n;i++){
		c[++cnt]=c[i];
		while(c[i]==c[i+1]){
			a[cnt]+=a[++i];
		}
	}
	int i=1,j=cnt;
	while(i<=j){
		if(a[i]==a[j]){
			if(c[i]!=c[j])ans+=a[i];
		}
		else{
			if(a[i]<a[j]){
				int x=a[j];
				if(sum[j-1]-sum[i]<x){
					for(i;i<j;i++){
						if(c[i]!=c[j]){
							ans+=a[i];
						}
					}
				}
				for(i;i<j&&x>=a[i];i++){
					x-=a[i];
					if(c[i]!=c[j]){
						ans+=a[i];
					}
				}
				if(x!=0){
					if(c[i]!=c[j]){
						ans+=min(a[i],x);
					}
					a[i]-=x;
				}
			}
			if(a[i]>a[j]){
				int x=a[i];
				if(sum[j-1]-sum[i]<x){
					for(j;j>i;j--){
						if(c[i]!=c[j]){
							ans+=a[j];
						}
					}
				}
				for(j;j>i&&x>=a[j];j--){
					x-=a[j];
					if(c[j]!=c[i]){
						ans+=a[j];
					}
				}
				if(x!=0){
					if(c[i]!=c[j]){
						ans+=min(a[j],x);
					}
					a[j]-=x;
				}
			}
		}
		i++,j--;
	}
	cout<<ans;
	return 0;
}

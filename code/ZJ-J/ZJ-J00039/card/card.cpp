#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[234567];
ll ans[234567];
int b[234567];
int main(){
		ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	//freopen(".in","r",stdin);
	//freopen(".out","r",stdout);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];if(i>1&&a[i]<a[i-1])f=0;
	} 
	if(f){
		for(int i=1;i<=n;i++){
			for(int j=a[i];j<=m;j++){
				ans[j]++;
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	}
	else {
		
		for(int i=1;i<=n;i++){
			memset(b,0,sizeof b);
			int l=0;
			for(int j=i;j<=n;j++){
				bool fl=1;
				for(int k=1;k<=l;k++){
					if(a[j]==b[k]){
						for(int o=k+1;o<=l;o++)b[o]=0;
						l=k;fl=0;
						break;
					}
				}
				if(fl)b[++l]=a[j];
			}
			for(int j=1;j<=l;j++)ans[b[j]]++;
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	}
	return 0;
} 

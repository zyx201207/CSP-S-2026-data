#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int ans=0,sum=0;
	for(int i=1;i<=n;i++){
		if(i!=1){
			for(int j=1;j<i;j++){
				sum+=abs(a[i]-a[j]);
			}
			if(m-sum!=0) sum=0;
			if(m-sum==0){
				if(a[i]!=a[i+1]){
					ans=i;
					cout<<ans;
					return 0;
				}
				else{
					ans=i;
					for(int j=i;j<=n;j++){
						if(a[j]==a[j+1]) ans++;
						else{
							cout<<ans;
							return 0;
						}
					}
				}
			}
			
		}
	}
	return 0;
} 

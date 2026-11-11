#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],mp[500005],mm[300005];
bool f[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		mp[i]=i;
	}
	for(int i=2;i<n;i++){
		for(int j=1;j<=n;j++){
			if(a[j]==a[i]){
				for(int k=i;k<j;k++){
					if(!f[i]){
						mp[k]-=i;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		mm[a[i]]=max(mp[i],mm[a[i]]);
	}
	for(int i=1;i<=m;i++){
		cout<<mm[i]<<' ';
	}
	return 0;
}

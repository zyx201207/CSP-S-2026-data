#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int q[300005];
int ans[300005];
int s[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		s[i]=q[a[i]];
		q[a[i]]=i;
	}
	bool v[300005];
	for(int i=1;i<=n;i++){
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++){
			if(v[a[j]]==0){
				v[a[j]]=1;
				ans[a[j]]++;
			}
			if(s[j]!=0){
				j=s[j]-1;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
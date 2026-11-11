#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int last[300005];
int add[500005];
int he[300005];
int ans[300005];
int q[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	bool x=true;
	for(int i=2;i<=n;i++){
		if(a[i]<=a[i-1]){
			x=false;
		}
	}
	if(x==true){
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(last[a[i]]==0){
			add[i]++;
			last[a[i]]=i;
		}
		else{
			add[i]=i-last[a[i]];
			add[last[a[i]]]+=last[a[i]]-i;
			last[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		he[i]=he[i-1]+add[i];
		for(int j=1;j<=i;j++){
			if(j==i){
				if(he[i]>0){
					q[i]++;
				}
			}
			else{
				if(he[i]-he[j]>=0){
					q[i]++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]=max(ans[a[i]],q[i]);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

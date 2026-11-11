#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001],q[100001],ans[1000001],r,top[5001][4001],f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=1;
		}
	}
	if(f==0){
	for(int i=1;i<=n;i++){
		memset(q,0,sizeof(q));
		memset(top,0,sizeof(top));
		r=1;
		q[1]=a[i];
		for(int j=i+1;j<=n;j++){
			if(a[j]>q[r])
			q[++r]=a[j];
		}
		for(int j=1;j<=r;j++){
			ans[q[j]]++;
		}
	}
		for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(q,0,sizeof(q));
		memset(top,0,sizeof(top));
		r=1;
		q[1]=a[i];
		for(int j=i+1;j<=n;j++){
			for(int k=1;k<=r;k++){
				if(a[j]==q[k]){
					r=k-1;
					break;
				}
			}
			q[++r]=a[j];
		}
		for(int j=1;j<=r;j++){
			ans[q[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
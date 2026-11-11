#include<bits/stdc++.h>
using namespace std;
const int M=3e5+10;
int n,m,a[M];
int sum[M];
int ans[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	a[0]=0;
	for(int i=1;i<=m;i++){
		cin>>a[i];
		sum[a[i]]+=1;
	}
	int head=0;
	
	for(int i=1;i<=n;i++){
		sum[a[head]]-=1;
		for(int j=1;j<=m;j++){
			if(sum[j]%2==1) ans[j]+=1;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
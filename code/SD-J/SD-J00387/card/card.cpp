#include<bits/stdc++.h> 
using namespace std;
int n,m,a[10005],ans[10005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int sum[105][505],top=1;
		for(int j=i;j<=n;j++){
			if(sum[top][a[j]]!=0)sum[++top][a[j]]++;
			else sum[top][a[j]]++;
		}
		for(int j=1;j<=n;j++){
			if(sum[top][j]!=0)ans[j]+=1;
			cout<<sum[top][j]<<" ";
		}cout<<endl;
	}
	cout<<endl;
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
/*
4 3
1 2 1 3
*/

#include <bits/stdc++.h>
using namespace std;
int a[300001];
int check[300001];
int ans[300001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		check[i]=0;
		ans[i]=0;;
	}
	for(int i=1;i<=n;i++){
		int cnt=i;
		for(int j=cnt;j<=n;j++){
			if(a[j]==a[cnt]&&j!=cnt){
				for(int k=cnt;k<j;k++){
					check[k]++;
				}
				cnt=j;
			}
		}
		ans[a[i]]+=i-check[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
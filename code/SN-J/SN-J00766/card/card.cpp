//姓名：霍梓颐 考号：SN-J00766 学校：西北大学附属中学 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],maxx[300005],vis[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx[a[i]]=i;
	}
	for(int j=1;j<=n;j++){
		int i=j;
		while(i<=n){
			vis[a[i]]++;
			i=maxx[a[i]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

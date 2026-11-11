#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[300005],vis[300005],cnt=1;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(vis[a[i]]==0){
			vis[a[i]]=1;
			cout<<cnt*(cnt+1)/2;
			cnt++;
		}
	}
	return 0;
} 

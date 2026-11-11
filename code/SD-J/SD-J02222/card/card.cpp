/*
没时间做了，空悲切 
*/
#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int card[n+5],ct[m+5],t;
	int ans[m+5]={0};
	int top=1,a[n+5];
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	for(int k=1;k<=n;k++){
		top=1;
		memset(ct,0,sizeof(int)*(n+5));
		for(int i=k;i<=n;i++){
			card[top]=a[i];
			top++;
			ct[a[i]]++;
			if(ct[a[i]]>1){
				top--;
				while(card[top-1]!=a[i]){
					top--;
				}
			}
		}
		for(int j=1;j<top;j++){
			ans[card[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 

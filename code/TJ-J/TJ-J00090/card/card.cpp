#include<bits/stdc++.h>
using namespace std;
int a[500005];
bool b[300005];
int ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!b[a[j]]){
				ans[a[j]]++;
				b[a[j]]=1;
			}
		}	
		for(int j=1;j<=m;j++){
			b[j]=0;
		}	
	}	
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 

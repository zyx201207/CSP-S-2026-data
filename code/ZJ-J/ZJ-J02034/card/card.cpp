#include<bits/stdc++.h>
using namespace std;
int a[10000001],b[10000001],cnt,ans;
bool vis[100000001];
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
			if(!vis[a[j]])b[++cnt]=a[j];
			else{
				while(b[cnt]!=a[j]){
					b[--cnt]=0;
				}
				
			}
		}
		int p=0;
		for(int k=1;k<=cnt;k++){
			if(b[k]==i){
				p=1;
				break;
			}
		}
		if(p)ans++;
		
	}
	cout<<ans;
	
	return 0;
}
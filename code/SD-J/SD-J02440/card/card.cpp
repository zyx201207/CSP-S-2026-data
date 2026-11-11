#include<bits/stdc++.h>
using namespace std;
long long n,m,vis[500010],x[500010],a[500010];
bool fun=1; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(x,0,sizeof(x));
		for(int j=i;j<=n;j++){
			if (x[a[j]]==0){
				x[a[j]]=1;
			}
			else{
				long long flag;
				for(int s=1;s<j;s++){
					if (a[s]==a[j]){
						flag=s;
					}
				}
				for(int s=flag;s<j;s++){
					x[a[s]]=0;
				}
				x[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if (x[j]==1){
				vis[j]++;
			} 
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


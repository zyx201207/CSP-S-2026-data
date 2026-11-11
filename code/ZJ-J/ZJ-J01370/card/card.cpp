#include<bits/stdc++.h>
using namespace std;
int a[200003],b[3009],ans[3009],z[100010],n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m>3007||n>200000){
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);
		memset(z,0,sizeof z);
		for(int j=i;j<=n;j++){
			if(b[a[j]]){
				int p=0;
				for(int f=1;f<=j-1;f++){
					if(p){
						b[z[f]]=0;
						z[f]=0;
					}
					if(z[f]==a[j]){
						p=1;
						z[f]=0;
					}
				}
				z[j]=a[j];
			}
			else{
				z[j]=a[j];
				b[a[j]]=1;
			}
		}
		for(int i=1;i<=m;i++){
			if(b[i]){
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

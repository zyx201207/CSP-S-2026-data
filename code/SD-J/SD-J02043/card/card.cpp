#include<bits/stdc++.h>
using namespace std;
int n,a[10000001],m,ans[1000001],b[10000001];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		
		for(int j=i;j<=n;j++) b[j]=a[j];
		for(int j=i;j<=n;j++){
			int flag=0;
			for(int x=i;x<j;x++){
				if(b[x]==b[j]){
					flag=1;
				}
				if(flag==1) b[x]=0;
			}
			
		}
		for(int j=i;j<=n;j++){
			//cout<<b[j]<<" ";
			ans[b[j]]++;
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
} /*10 3
 3 1 2 1 3 2 3 1 2 1*/

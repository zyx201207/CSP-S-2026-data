#include<bits/stdc++.h>
using namespace std;
int a[500003];
bool flag[500003]={true};
int sum[300003];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	for(int t=1;t<=n;t++){
		for(int i=1;i<=n;i++){
			flag[i]=true;
		}
		for(int i=t;i<=n;i++){
			for(int j=t;j<i;j++){
				if(a[j]==a[i]&&flag[j]){
					for(int k=j;k<i;k++){
						flag[k]=false;
					}
				}
			}
		}
		for(int i=t;i<=n;i++){
			sum[a[i]]+=flag[i];
		}	
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[500009],tong[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(tong[a[i]]==0){
			tong[a[i]]++;
		}else{
			for(int j=1;j<=i;j++){
				if(a[j]==a[i]){
					while(j<=i){
						tong[a[j]]--;
						j++;
					}	
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<tong[i]<<" ";
	}
	return 0;
}


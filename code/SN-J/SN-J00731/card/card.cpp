//刘子墨SN-J00731西安交通大学附属中学 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[5000100],b[5000100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int flag=false;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			for(int k=j-1;k>=i;k--){
				if(a[j]==a[k]){
					flag=true;
					break;	
				}	
			}
			if(!flag){
				b[j]++;
			}
			else{
				break;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000+10],b[100000+10];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){//游戏局数 
		for(int j=i;j<=n;j++){//每局可以使用的牌 
			for(int x=j-1;x>=i;x--){
				if(a[j]==a[x]){
					for(int y=j;y>x;y--)
						a[y]=0;
					break;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(a[j]!=0) b[a[j]]++;
	    }
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}

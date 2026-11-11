#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int arr[N];
int ci[N];
int pai[N];
int vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&arr[i]);
	}
	int len=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vis[j]=0;
		}
		for(int j=i;j<=n;j++){
			++len;
			pai[len]=arr[j];		
			for(int k=1;k<=len;k++){
				if(pai[k]==arr[j]){
					len=k;
					break;
				}
			}
		}
		for(int k=1;k<=len;k++){
			if(!vis[pai[k]]){
				ci[pai[k]]++;
				vis[pai[k]]=1;
			}
		}
		len=0;
	}
	for(int i=1;i<=m;i++){
		cout<<ci[i]<<' ';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=5e5,M=3e5;
int n,m,a[N+5],ans[M+5];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool o=0;
			for(int z=j+1;z<=n;z++){
				if(a[j]==a[z]){
					j=z-1;
					o=1;
					break;					
				}
			}
			if(o==0)ans[a[j]]++;
		}
	}
	for(int j=1;j<=m;j++)cout<<ans[j]<<" ";
} 

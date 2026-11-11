#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N=5e5+10;
long long a[N],ans[N],now,a1[N],a2[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
		long long nw[10];
		for(int i=1;i<=n;i++){
			long long id=0;
			for(int j=i;j<=n;j++){
				id++;
				nw[id]=a[j];
				for(int k=1;k<id;k++){
					if(nw[id]==nw[k]){
						id=k;
						break;
					}
				}
			}
			for(int j=1;j<=id;j++){
				ans[nw[j]]+=1;
			}
		}
		for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	
	return 0;
}
/*
*/

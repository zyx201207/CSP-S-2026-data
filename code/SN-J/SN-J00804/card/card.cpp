//SN-J00804 张馨月 西安翱翔中学 
#include<bits/stdc++.h>
using namespace std;
int n,m;
int vis[300005]={0};
int a[500005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	int ii=1;
	int s=n;
	while(s--){
		vis[a[ii]]++;
		for(int i=ii;i<=n;i++){
			if(a[i]==a[i-1]){
				continue;
			}
			else if(a[i]>a[i-1]&&ii!=i){
				vis[a[i]]++;
			}
		}
		ii++;
	}
	for(int i=1;i<=m;i++){
		cout<<vis[i]<<" ";
	}
	
	
	return 0;
}

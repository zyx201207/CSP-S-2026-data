#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long a[N],du[N],b[N];
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof b);
		for(int j=i;j<=n;j++){
			if(b[a[j]]==1){
				memset(b,0,sizeof b);
//				vis[a[j]]=false;
				b[a[j]]=1;
			}
			else{
				b[a[j]]++;
			}
		}
//		for(int )
		for(int j=1;j<=m;j++){
//			cout<<j<<" "<<b[j]<<endl;
			if(b[j]!=0){
				du[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<du[i]<<" ";
	return 0;
}

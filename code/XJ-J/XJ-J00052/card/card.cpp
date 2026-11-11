#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
long long int n,m,a[N],ans[N],vis[N],k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		vis[a[i]]++;
		if(vis[a[i]]>1){
			ans[k]++;
		}
	}
	cout<<n<<3<<4;
	return 0;
} 

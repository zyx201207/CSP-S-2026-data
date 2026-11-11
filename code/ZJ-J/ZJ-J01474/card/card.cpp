#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ne[500010],t[500010],da[500010];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=n;i>=1;i--){
			if(t[a[i]]) ne[i]=t[a[i]];
			else ne[i]=i+1;
			t[a[i]]=i;
		}
		int used[m+1];
		for(int i=1;i<=n;i++){
			memset(used,0,sizeof(used));
			for(int j=i;j<=n;j=ne[j]){
				if(!used[a[j]]) da[a[j]]++;
				used[a[j]]=1;
			}
		}
		for(int i=1;i<=m;i++) cout<<da[i]<<" ";
	}else for(int i=1;i<=m;i++) cout<<n<<" ";
}

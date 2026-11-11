#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],n,m,t[M],b[M],cnt;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		map<int,bool> mp;
		memset(b,0,sizeof(b));
		cnt=0;
		for (int j=i;j<=n;j++){
			int k;
			for (k=1;k<=cnt;k++){
				if(b[k]==a[j]) break;
			}
			cnt=cnt-(cnt-k+1);
			b[++cnt]=a[j];
		}
		for (int j=1;j<=cnt;j++){
			if(!mp[b[j]]){
				t[b[j]]++;
				mp[b[j]]=true;
			}
		}
	}
	for (int i=1;i<=m;i++) cout<<t[i]<<" ";
	return 0;
}

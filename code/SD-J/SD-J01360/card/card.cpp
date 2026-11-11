#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5,M = 3e5 + 5;
int n,m,x=1,idx;
int a[N],ans[M],sta[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int x=1;x<=n;x++){
		idx=0;
		for(int i=x;i<=n;i++){
			for(int j=1;j<=idx;j++) if(sta[j]==a[i]) idx=j-1;
			sta[++idx]=a[i];
		}
		for(int i=1;i<=idx;i++)
			ans[sta[i]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

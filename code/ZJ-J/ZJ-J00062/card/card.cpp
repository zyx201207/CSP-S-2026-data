#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e5+100;
const int MAXM=3e5+100;

int n,m;
int a[MAXN];
bool ok[MAXM];
int d[MAXN],pre[MAXN],ans[MAXN];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=n;i>=1;i--){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(i==1) d[i]=n;
		else d[i]=-1;
	}
	for(int i=1;i<=n;i++){
		if(ok[a[i]]==0){
			ok[a[i]]=1;
			pre[a[i]]=i;
		}
		else{
			d[pre[a[i]]+1]--;
			d[i]++;
			pre[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		d[i]+=d[i-1];
		ans[a[i]]=max(ans[a[i]],d[i]);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=200005,MAXM=300005;
ll n,m,lst[MAXM],sumn[MAXN],ans[MAXM],a[MAXN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			lst[j]=0;
		}
		int L=i;
		for(int j=i;j<=n;j++){
			int now=a[j];
			if(lst[now] and lst[now]>=L){
				L=j;
			}
			lst[now]=j;
		}
		sumn[L]++;
	}
	for(int i=1;i<=n;i++){
		sumn[i]=sumn[i-1]+sumn[i];
	}
	for(int i=1;i<=n;i++){
		ans[a[i]]+=sumn[i];
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N],d[N],cnt[N];
int b[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=n;i>0;i--){
		if (d[a[i]]==0) d[a[i]]=i;
	}for (int i=1;i<=n;i++){
		cnt[a[i]]+=i;
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++) b[j]=0;
		for (int j=i;j<=n;j++){
			if (d[a[j]] != j){
				for (int k=j+1;k<=d[a[j]];k++) b[a[k]]++;
			}
		}for (int j=i;j<=n;j++) cnt[a[j]]-=b[j];
	}for (int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
	fclose(stdin);
	fclose(stdout);
}

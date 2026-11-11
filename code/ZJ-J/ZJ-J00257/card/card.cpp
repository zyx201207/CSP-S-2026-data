#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5,M=3e5+5;
int n,m,Top;
int a[N];
int stk[N];
int ans[M];
int cnt[M];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=5000){
		for(int i=1;i<=n;i++){	
			Top=0;
			for(int j=1;j<=m;j++) cnt[j]=0;
			for(int j=i;j<=n;j++){
				if(cnt[a[j]]>0){
					while(stk[Top]!=a[j]) cnt[stk[Top]]--,Top--;
					cnt[stk[Top]]--;Top--;
				}
				stk[++Top]=a[j];
				cnt[a[j]]++;
			}
			for(int j=1;j<=m;j++) ans[j]+=cnt[j];
		}
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++) ans[a[i]]++;
		for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
		return 0;
	}
	return 0;
}
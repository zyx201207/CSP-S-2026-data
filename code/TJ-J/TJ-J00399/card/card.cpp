#include <bits/stdc++.h>
using namespace std;
int a[500005];
int Cnt[300005];
int Ans[300005];
int Num[500005];
bool vis[500005];
bool vistd[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1){
		cout<<n;
		return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
			for(int k=i;k<=n;k++){
			Cnt[a[k]]=0;
			Num[a[k]]=0;
			vis[a[k]]=0;
			vistd[a[k]]=0;
	}
		for(int k=i;k<=n;k++){
			Cnt[a[k]]++;
			if(Cnt[a[k]]<2){
				Num[a[k]]=k;
			}
			else {
				for(int j=Num[a[k]];j<k;j++){
					Cnt[a[j]]--;
				}
				Num[a[k]]=k;
				vis[a[i]]=1;
		}} 
		for(int q=i;q<=n;q++){
			if(Cnt[a[q]]>0 && vistd[a[q]]==0){
				if(vis[a[q]]==1){
					vistd[a[q]]=1;
				}
				Ans[a[q]]++;
				}
			else continue;
}
	}
	for(int i=1;i<=m;i++){
			cout<<min(n,Ans[i])<<" ";
}
	return 0;
}

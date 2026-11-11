#include<bits/stdc++.h>
#define N 500050
#define M 300050
using namespace std;
bool Spe_A=1;
int n,m,a[N],lst[M],cnt[M];
void solve_A (){
	for (int i=1; i<=m; i++){
		cout<<lst[i]<<" ";
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1; i<=n; i++){
		cin>>a[i];
		lst[a[i]]=i;
		if (a[i]<a[i-1]){
			Spe_A=0;
		}
	}
	if (Spe_A){
		solve_A ();
		return 0;
	}
	for (int t=1; t<=n; t++){
		for (int i=t; i<=n; i++){
			cnt[a[i]]++; i=lst[a[i]];
		}
	}
	for (int i=1; i<=m; i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

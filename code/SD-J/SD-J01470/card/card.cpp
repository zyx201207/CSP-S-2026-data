#include<bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
ui n,m,a[500010]={},desk[500010]={},num=0,k,cnt[300010]={};
ui index(ui k){
	for (ui i=1;i<=num;i++){
		if (desk[i]==k) return i;
	} return 0;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(false);
	cin>>n>>m;
	for (ui i=1;i<=n;i++) cin>>a[i];
	for (ui i=1;i<=n;i++) {
		for (ui j=i;j<=n;j++) {
			k = a[j];
			ui i_k=index(k);
			if (i_k){
				fill(desk+i_k,desk+num,0);
				num=i_k-1;
			} else desk[num++]+=1;
		} 
		bool have[300010]={};
		for (ui j=1;j<=num;j++) {
			if (!have[desk[j]]){cnt[desk[j]]+=1;have[desk[j]]=true;}
		}
	}
	for (ui i=1;i<=m;i++) cout<<cnt[i]<<" ";
	fclose(stdin); fclose(stdout);
	return 0;
}

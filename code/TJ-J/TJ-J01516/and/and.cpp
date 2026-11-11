#include<bits/stdc++.h> 
using namespace std;
int n,m;
int a[2000005];
int joker[2000005];
int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i!=j) ans=max(ans,a[i]^a[j]);
			}
		}
		cout<<ans;
	}
	if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if(i!=j&&j!=k&&k!=i) ans=max(ans,a[i]^a[j]^a[k]);
				}
			}
		}
		cout<<ans;
	}
	int ans=0;
	for(int i=1;i<=m;i++) joker[i]=i;
	while(joker[1]>=n-m+1){
		int ccmp=1,ttmp=0,bz=1;
		tmp=joker[1];
		for(int i=2;i<=m;i++) tmp^=joker[i];
		int cmp=m;
		while(joker[cmp]==n){
			joker[cmp]=m-ccmp;
			cmp--;
		}
		if(joker[1]!=bz) bz++,ttmp++;
		if(joker[1]>=n-m+1) break;
		ans=max(ans,tmp);
	}
	cout<<ans;
	return 0;
}

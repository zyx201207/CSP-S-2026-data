#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
int a[505];
int b[505],ans[205];
bool flag[205];
void solve(void){
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int g=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(flag[a[j]]){
				int t=-1;
				for(int k=1;k<=g;k++){
					if(b[k]==a[j]){
						t=g;
					}
					else if(t>-1){
						flag[b[k]]=false;
					}
				}
				
			}else{
				g++;
				flag[a[j]]=true;
				b[g]=a[j];
			}
		}
		for(int j=1;j<=m;j++){
			ans[j]+=flag[j];
		}
		memset(b,0,sizeof(b));
		memset(flag,0,sizeof(flag));
		g=0;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
}
int main(){
	//freopen("card.in","r",stdin);
	//freopen("card.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}


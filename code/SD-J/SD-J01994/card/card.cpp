#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans[N];
int now[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==1){
		cout<<n;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(now[a[j]]){
				for(int k=1;k<=m;k++){
					now[k]=0;
				}
				now[a[j]]=1;
			}else{
				now[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			if(now[j]){
				ans[j]++;
			}
		}
		for(int j=1;j<=m;j++){
			now[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int flag[N];
int q[N],t;
int ans[N];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			flag[j]=0;
		}
		t=0;
		for(int j=i;j<=n;j++){
			if(flag[a[j]]==0){
				flag[a[j]]=++t;
				q[t]=a[j];
			}else{
				for(int k=flag[a[j]]+1;k<=t;k++){
					flag[q[k]]=0;
				}
				t=flag[a[j]];
			}
		}
		for(int j=1;j<=m;j++){
			if(flag[j]>0){
				ans[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+7,M=3e5+7;
int n,m,a[N],stk[N],tot;
map<int,int> ans;
signed main(){
	freopen("card1.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		tot=0;
		for(int j=i;j<=n;j++){
			bool f=0;
			for(int k=1;k<=tot;k++)
				if(a[k]==a[j]&&k!=j){
					tot=k;f=1;break;
				}
			stk[++tot]=a[j];
		}for(int j=1;j<=tot;j++)
			ans[stk[j]]=1;
	}for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
}


#include<bits/stdc++.h>
#define int long long
using namespace std;
bool bj[300005];
int n,m,a[500005],cnt[300005]; 
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(bj,0,sizeof(bj));
		stack<int>st;
		for(int j=i;j<=n;j++){
			if(bj[a[j]]){
				while(st.top()!=a[j]){
					bj[st.top()]=0;
					st.pop();
				}
				st.pop();
			}
			bj[a[j]]=1;
			st.push(a[j]);
		}
		for(int j=1;j<=m;j++){
			if(bj[j]){
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}


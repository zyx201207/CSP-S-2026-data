#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int cnt=0LL;
int n,m,ans[N],a[N],vis[N];
stack<int> st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]),cnt+=(a[i]>=a[i-1]);
	if(cnt==n&&n*n>=100000000LL){
		//B
		map<int,int> g;
		for(int i=1;i<=n;i++) g[a[i]]++;
		int sum=0LL;
		for(int i=1;i<=m;i++){
			sum+=g[i];
			int answ=0LL;
			if(g[i]==0){
				printf("0 ");
			}
			else printf("%lld ",sum);
		}
		return 0;
	}
	for(int i=1;i<=n;i++){for(int j=1;j<=m;j++) vis[j]=0;
		
		while(!st.empty()){
			st.pop();
		}
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				while(!st.empty()&&(st.top()!=a[j])) vis[st.top()]=0,st.pop();
			}
			else{
				vis[a[j]]=1;
				st.push(a[j]);
			}
		}
		while(!st.empty()){
			ans[st.top()]++;
			st.pop();
		}
	}
	for(int i=1;i<=m;i++) printf("%lld ",ans[i]);
	return 0;
}
/*
//freopen
luogu uid:1803320 guan zhu yi xia ba qwq
100+100+100+52=352 
*/

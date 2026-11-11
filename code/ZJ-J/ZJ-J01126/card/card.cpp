#include<bits/stdc++.h>
using namespace std;
typedef int ll;
ll n,m,a[500010],q[300010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) q[j]=0;
		stack<ll> st;
		for(int j=i;j<=n;j++){
			if(q[a[j]]==0){
				q[a[j]]++;
				st.push(a[j]);
			}
			else{
				while(!st.empty()){
					ll x=st.top();
					q[x]--;
					st.pop();
					if(x==a[j]) break;
				}
				q[a[j]]++;
				st.push(a[j]);
			}
		}
		while(!st.empty()){
			ll x=st.top();
			st.pop();
			ans[x]++;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}

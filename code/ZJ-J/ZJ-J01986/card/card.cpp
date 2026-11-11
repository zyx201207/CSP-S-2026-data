#include<bits/stdc++.h>
using namespace std;
typedef long long bro;
bro n,m,a[200005],vis[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;++i){
		cin>>a[i];
	}
	stack<bro>st;
	for(bro i = n;i >= 1;++i){
		if(vis[a[i]] == 0){
			st.push(a[i]);
			vis[a[i]]++;
			ans[a[i]] += i;
		}else{
			bro p = st.top();
			while(p != a[i]){
				ans[p] -= i;
				vis[p]--;
				st.pop();
				p = st.top();
			}
		}
	}
	for(int i = 1;i <= m;++i){
		cout<<ans[i]<<' ';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int ans[500005];
int t[500005];
stack <int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int k=1;k<=n;k++){
		
		memset(t,0,sizeof(t));
		for(int i=k;i<=n;i++){
			while(t[a[i]]==1){
				t[q.top()]--;
				q.pop();		
			}
			q.push(a[i]);
			t[a[i]]++;
		}
		while(!q.empty()){
			int o=q.top();
			ans[o]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
/*4 3
1 2 1 3
Trick||Treat!
*/

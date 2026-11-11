#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M];
int vis[M];
//vector <int> ans;
stack <int> s;
int main(){
	freopen ("card.in","r",stdin);
	freopen ("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=n;
	
	while (t--){
//		cout<<t<<" ";
		memset(vis,0,sizeof(vis));
		for (int j=n-t;j<=n;j++){
			int x=a[j];
			if (vis[x]){
				vis[x]=0;
				while (s.top()!=x){
					s.pop();
				}
				s.pop();
			}
			vis[x]=1;
			s.push(x);
		}
		while (!s.empty()){
			int y=s.top();
			ans[y]++;
			s.pop();
//			cout<<"haha";*/
		}
//		cout<<"\n\n";
	}
//	int len=ans.size();
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}






//goodbye my CSP-J




































































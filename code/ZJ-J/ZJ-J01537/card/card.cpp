#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],ANS[M];
bool vis[M];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			vis[j]=0;
		}
		stack<int> s;
		for(int j=i;j<=n;j++){
			int x=a[j];
			if(vis[x]==0){
				vis[x]=1;
				s.push(x);
			}
			else{
				while(!s.empty()){
					int X=s.top();
					s.pop();
					vis[X]=0;
					if(X==x){
						break;
					}
				}
				vis[x]=1;
				s.push(x);
			}
		}
		while(!s.empty()){
			int X=s.top();
			s.pop();
			ANS[X]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ANS[i]<<" ";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
long long a[N];
long long b[N];
stack<int> stk;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		bool st[N]={false};
		for(int j=i;j<=n;j++){
			if(!st[a[j]]){
				stk.push(a[j]);
				st[a[j]]=true;
			}
			else{
				int f=0;
				while(!f){
					st[stk.top()]=false;
					if(stk.top()==a[j]){
						stk.pop();
						break;
					}
					stk.pop();
				}
				stk.push(a[j]);
				st[stk.top()]=true;
			}
		}
		while(stk.size()){
			b[stk.top()]++;
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}

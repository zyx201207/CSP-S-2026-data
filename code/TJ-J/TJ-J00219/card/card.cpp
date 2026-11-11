#include<bits/stdc++.h>
using namespace std;
int n,m;
stack<int> s;
int a[500009];
int ans[300009];
bool OnTable[300009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(OnTable[a[j]]){
				while(s.top()!=a[j]){
					OnTable[s.top()]=false;
					s.pop();
				}
				s.pop();
			}
			s.push(a[j]);
			OnTable[s.top()]=true;
		}
		while(!s.empty()){
			ans[s.top()]++;
			s.pop();
		}
		memset(OnTable,0,sizeof(OnTable));
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[300005];
stack<int>s;
bool b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int j=1;j<=n;j++){
		for(int i=j;i<=n;i++){
			if(b[a[i]]){
				while(a[i]!=s.top()){
					b[s.top()]=0;
					s.pop();
				}
			}
			else{
				b[a[i]]=1;
				s.push(a[i]);
			}
		}
		while(!s.empty()){
			b[s.top()]=0;
			ans[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ui unsigned int
#define ull unsigned long long
int n,m,visz[300010],a[500010];
bool vis[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n>5000){
		for(int i=1;i<=n;i++){
			if(a[i+1]!=a[i]) visz[a[i]]+=i;
			else{
				while(a[i+1]==a[i]){
					i++;
				}
				visz[a[i]]+=i;
			}
		}
		for(int i=1;i<=m;i++) cout<<visz[i]<<' ';
		return 0;
	}
	for(int si=1;si<=n;si++){
		stack<int>q;
		for(int i=si;i<=n;i++){
			if(!vis[a[i]]){q.push(a[i]); vis[a[i]]=1;}
			else{
				while(q.top()!=a[i]){
					vis[q.top()]=0;
					q.pop();
				}
			}
		}
		while(!q.empty()){
			visz[q.top()]++;
			vis[q.top()]=0;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++) cout<<visz[i]<<' ';
	return 0;
}

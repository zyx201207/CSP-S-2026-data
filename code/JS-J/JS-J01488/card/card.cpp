#include<iostream>
#include<stack>
#define ll long long
#define N 500005
using namespace std;

stack<ll>s;
bool vis[N];
ll a[N],n,m;
ll t[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(vis[j]){
				while(!s.empty() && a[s.top()]!=a[j]){
					vis[s.top()]=false;
					s.pop();
				}
				if(!s.empty() && a[s.top()]==a[j]){s.pop();vis[j]=false;}
			}
			s.push(j);
			vis[j]=true;
		}
		cerr<<i<<"\n";
		while(!s.empty()){
			t[a[s.top()]]++;
			vis[s.top()]=false;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
}
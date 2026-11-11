#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll n,m,a[N],ans[N];
queue<ll> q1,q2;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		q1.push(a[i]);
		for(int j=i+1;j<=n;j++){
			while(!q1.empty()){
				if(a[j]!=q1.front()){
					q2.push(q1.front());
					q1.pop();
				}
				else break;
			}
			while(!q1.empty()){
				q1.pop();
			}
			while(!q2.empty()){
				q1.push(q2.front());
				q2.pop();
			}
			q1.push(a[j]);
		}
		while(!q1.empty()){
			ans[q1.front()]++;
			q1.pop();
		}
	}
	for(int i=1;i<=n;i++){
		if(ans[i]==0) continue;
		cout<<ans[i]<<' ';
	}
	return 0;
}

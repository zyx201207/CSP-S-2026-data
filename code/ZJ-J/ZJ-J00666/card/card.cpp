#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,now=0;
ll a[500010];
ll ans[300010];
ll h[500010];
stack<ll> s;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(h,0,sizeof(h));
		now=1;
		for(int j=i;j<=n;j++){
			if(!h[a[j]]){
				h[a[j]]=now;
				s.push(a[j]);
			}else{
				for(int k=1;k<=now-h[a[j]];k++){
					s.pop();
				}
				now=h[a[j]];
				//h[a[j]]=now;
				s.push(a[j]);
			}
			now++;
		}
		while(!s.empty()){
			//cout<<s.top();
			ans[s.top()]++;
			s.pop();
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
/*
4 3
1 2 1 3

*/

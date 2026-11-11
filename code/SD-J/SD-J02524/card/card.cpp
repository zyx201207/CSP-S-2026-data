#include <bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int n,a,r,x;
queue<long long> q;
bool st[N];
int main(){
    freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x;
		q.push(x);
		if(x==i){
			a[i]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<" ";
	}
}

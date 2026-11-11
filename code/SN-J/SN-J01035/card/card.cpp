#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
typedef long long ll;
int n,m,a[N],q[N],mx[N];
queue<int>T[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		T[a[i]].push(i);
		mx[a[i]]=i;
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=m;j++){
			if(T[a[i]].front()<mx[a[i]])maxx=max(maxx,T[a[i]].front());
		}
		for(int i=maxx;i<=m;i++){
			q[a[i]]++;
		}
		T[a[i]].pop();
	}
	for(int i=1;i<=m;i++)cout<<q[i]<<" ";
}

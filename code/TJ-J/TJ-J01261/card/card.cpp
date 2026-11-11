#include<bits/stdc++.h>
using namespace std;
bool flag;
int n,m;
const int N=5e5+10;
int a[N];
vector<int> g[N];
int num[N];
void solve(int l){
	if(l>n) return ;
	int k=g[a[l]][g[a[l]].size()-1];
	while(k<=n and g[a[k]][g[a[k]].size()-1]==k){\
		num[a[k]]++;
		k++;
	}
	solve(k);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1] and i!=1) flag=0;
		g[a[i]].push_back(i);
	}
	if(flag){
		for(int i=1;i<=m;i++){
			cout<<i<<' ';
		}return 0;
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<' ';
	}return 0;
}

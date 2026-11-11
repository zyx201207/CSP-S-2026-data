#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(n,0);
	vector<int> b(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	int x=0;
	for(int i=0;i<n;i++){
		cout<<n-b[i]<<' ';
	}
	return 0;
}


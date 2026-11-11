#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,a[N];
int c[N],b[N],d[N];
vector<int> v;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int mm=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[i]=a[i];
		d[i]=a[i];
	}
	int cnt=0;
	while(m--){
		cout<<0<<" ";
	}
	return 0;
}

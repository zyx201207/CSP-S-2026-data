#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
using ll=long long;
const int N=5e5+10;
const int M=3e5+10;
int a[N];
int b[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	fast;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int k=0;
	while(k<n){
		k++;
		int c[N];
		vector<int> q;
		for(int i=1;i<=n;i++) c[i]=a[i];
		for(int i=k;i<=n;i++){
			bool f=0;
			int cnt=0;
			for(auto &j:q){
				if(j==a[i]){
					f=1;
				}
				else if(f==1) cnt++;
			}
			for(int j=1;j<=cnt;j++) q.pop_back();
			if(f==0) q.push_back(a[i]);
		}
		for(auto &i:q) b[i]++;
		for(int i=1;i<=n;i++) a[i]=c[i];
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N=2e5+5;
long long a[N];
bool b[N][32];
int x[N];
int ans[N];
int main(){
//	freopen("and.in","r",stdin);
//	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		long long q=a[i];
		while(q){
			b[i][x[i]++]=q%2;
			q/=2;
		}
	}
	int p=0;
	for(int i=31;i>=0;i--){
		p=0;
		for(int j=0;j<n;j++){
			if(b[j][i]){
				ans[p++]=j;
			}
		}
		if(p>=m){
			break;
		}
	}
	long long l=a[ans[0]];
	for(int i=0;i<p;i++){
		l&=a[ans[i]];
	}
	cout<<l;
	return 0;
}

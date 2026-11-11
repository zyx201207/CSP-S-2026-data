#include<bits/stdc++.h>
const int N=1e5+10;
using namespace std;
int n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n-1;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]<a[j]){
				swap(a[i],a[j]);
			}
		}
	}int p=a[1];
	for(int i=2;i<=m;i++){
		p=p&a[i];
	}
	cout<<p;
	return 0;
}

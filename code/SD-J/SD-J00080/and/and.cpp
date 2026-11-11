#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long n,m;
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int max=-1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			for(int x=i;x<=n;x++){
				int ch=a[i]&a[x];
				if(ch>max&&a[i]!=a[x]){
					max=ch;
				}
			}
		}
	}
	cout<<max;
	return 0;
}

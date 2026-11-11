#include <bits/stdc++.h>
using namespace std;
int a[200005];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m,maxx=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=1;i<=n;i++){
		int s=a[1];
		for(int j=1;j<m;j++){
			if(i+j<=n){
				s=s&a[i+j];
			}
		}
		maxx=max(maxx,s);
	}
	cout<<maxx;

	return 0;
}

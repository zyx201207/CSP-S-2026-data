#include <bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,m,ma,l,r,x,a[N],k,b;
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		x=a[i];
		for(int j=i+1,k=1;j<=n;j++){
			x=x&a[j];
			ma=max(ma,x);
			if(k==m-1){
				x=a[i];
				k=0;
			}
		}
	}
	cout<<ma;
	return 0;
}

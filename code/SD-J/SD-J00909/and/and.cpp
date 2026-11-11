#include<bits/stdc++.h>
using namespace std;
const int N=100007;
int n,m,a[N],b[N];
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			b[i]=(a[i] and a[j+1]);
			
		}
	}
	int maxx=0;
	for(int i=1;i<=n;i++){
		maxx=max(b[i],b[i+1]);
	}
	cout<<a[3];
	return 0;
}                                                                   

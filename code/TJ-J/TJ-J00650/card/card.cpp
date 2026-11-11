#include<bits/stdc++.h>
using namespace std;
#define N 500005
long long n,m,a[N],ans[N],t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	t=m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cout<<i;
	}
}

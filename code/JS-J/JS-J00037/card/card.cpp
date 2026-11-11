#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int a[maxn];
int b[maxn];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cout<<b[i]<<" ";
	}
    return 0;
}

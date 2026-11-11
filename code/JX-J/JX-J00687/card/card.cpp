#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,ans=0,a[N],b[N],i1,i2,a1,a2;
int main(){
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>=1;i--){
		cout<<i<<" ";
	}
    return 0;
}

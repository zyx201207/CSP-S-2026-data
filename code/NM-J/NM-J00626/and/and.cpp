#include <bits/stdc++.h>
using namespace std;
long long f[200010];
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
long long n,m;
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>f[i];
}
sort(f+1,f+n+1);
cout<<f[n+1-m];
return 0;
}




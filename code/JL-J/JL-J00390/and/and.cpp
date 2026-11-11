#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10000001],b,c;
int main(){
freopen("and","r",stdin);
freopen("and","w",stdout);

cin>>n>>m;
b=n-m;
c=n-b;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);

    cout<<a[c];
return 0;
}



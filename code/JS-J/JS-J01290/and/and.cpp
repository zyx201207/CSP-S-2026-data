#include <bits/stdc++.h>
using namespace std;
long long a[200000];
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int n,m;cin>>n>>m;
long long maxn=0,r;
for(int i=0;i<=n-1;i++){
    cin>>a[i];
}
for(int i=0;i<=n-m;i++){
        r=a[i];
    for(int j=i+1;j<=n-m+1;j++){
        for(int s=j;s<=m+j-2;s++){
            r=r&a[s];
        }
        if(r>maxn){
            maxn=r;
        }

    }

}
cout<<maxn;
return 0;
}

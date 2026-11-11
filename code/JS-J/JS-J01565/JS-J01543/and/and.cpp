#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005];
int main()
{
    freopen("and.in","r","stdin");
    freopen("and.out","w","stdout");
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int max=0;
    for(int i=1;i<=n;i++){
        for(int j=2;j<=m+2;j++){
            if(max<=(a[i] and a[j])){
                max==(a[i] and a[j]);
            }
        }
    }
    cout<<max;
    return 0;
}

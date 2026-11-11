#include <bits/stdc++.h>
#define st string
using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m,maxai=0;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[n]>maxai){
            maxai=a[i];
        }
    }
    if(m==1){
        cout<<maxai;
    }
    if(n==m){
        int cnt=a[0];
        for(int i=1;i<n;i++){
            cnt&=a[i];
        }
        cout<<cnt;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,x,m,l,r;
string y,a;
int main ()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>n;
    for (int i=1;i<=n;i++){
        cin >>x>>y;
        r+=x;
        for (int j=1;j<=x;j++){
            a+=y;
        }
    }
    l=0;
    while(r>=l){
        if(a[r]!=a[l]){
            m++;
        }
        l++;
        r--;
    }
    cout <<m;
    return 0;
}

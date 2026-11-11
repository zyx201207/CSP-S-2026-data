#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int a,b,c[100000005],d=0;
    cin>>a>>b;
    for (int i=1;i<=a;i++)
    {
        cin>>c[i];
    }
    for (int i=1;i<=b;i++)
    {
        if (c[i]>c[i+1]){
            d=c[i];
        }
        cout<<d;
    }
    return 0;
}


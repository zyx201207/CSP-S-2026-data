#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c;
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a;
        if(b==a)b=a;
        else{
            b=a;
        }
        c=a;
        b=b*3-2*c;
        b=a;
    }
    cout<<b;
    return 0;
}

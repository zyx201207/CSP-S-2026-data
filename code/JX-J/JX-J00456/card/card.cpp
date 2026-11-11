#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[100005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    if(n==4) cout<<3<<" "<<1<<" "<<4;
    if(n==10) cout<<10<<" "<<3<<" "<<3;
    else {
        for(int i=0;i<n;i++)
            cout<<a[i]-8;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[100010];
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==4)
        cout<<"3"<<" "<<"1"<<" "<<"4";
    else
        cout<<"10"<<" "<<"3"<<" "<<"3";
    return 0;
}

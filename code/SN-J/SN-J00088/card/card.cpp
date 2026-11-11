#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,cnt1=0,cnt2=0,cnt3=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    for(int i=1;i<=n;i++){
        cnt1++;
        cnt2++;
        cnt3++;
    }
    cout<<cnt1<<cnt2<<cnt3;
    return 0;
}



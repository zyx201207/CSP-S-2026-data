#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,a;
    long long card[500005];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a;
        card[i]=a;
    }
    while(n){



        n-=1;
    }


    for(int i=1;i<=n;i++){
        cout<<card[i];
    }
    cout<<n<<m;
    return 0;
}

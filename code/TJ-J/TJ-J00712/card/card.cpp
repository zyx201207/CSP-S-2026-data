#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[10000000];
long long oc=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        for(int i=0;i<=n;i++){
            oc=a[i]oc;
        }
    }
    if(m==1){
        oc==0;
        for(int i=o;i<=n;i++){
            if(oc<=a[i])

        }
    }

    return 0;
}



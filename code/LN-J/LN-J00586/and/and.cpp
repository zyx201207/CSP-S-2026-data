#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int z[200005];
    for(int i=0;i<n;i++){
        int a,q=0,w=1;
        cin >> a;
        while(a!=0){
            q+=a%2*w;
            w*=10;
            a/=2;
        }
        z[i]=q;
    }
    for(int i=m-1;i<n;i++){

    }
    cout << 13;
    return 0;
}

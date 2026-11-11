#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int best = 0;
    for( int i = 1 ; i <= n ; i++ ){
        int t ;
        cin >>t;
        if( best < t ){
            best = t;
        }
    }
    cout<<best;
    return 0;
}

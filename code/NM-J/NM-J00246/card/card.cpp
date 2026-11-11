#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >>n>> m;
    int l [5005] = {};
    int cnt[3005] = {};
    for( int i = 1 ; i <= n ; i++){
        cin >> l[i];
    }
    int num = 1;
    for( int i = num ; i <= n ; i++){//lunci
        int l2[5005] = {};
        for( int j = i ; j <= n ; j++){
            l2[j] = l[j];
            bool s = false;
            for(int k = i ; k < n ; k++ ){
                if( s == true ){
                    l2[k] = -1;
                }
                if( l2[k] == l[j-1] && s== false ){
                    l2[k] = -1;
                    s = true;
                }
            }
            for( int k = i ; k <= n ; k++ ){
                if( l2[k] != -1 ){
                    cnt[l2[k]]++;
                }
            }
        }
    }
    int ll[5005] = {};
    for( int i = 1 ; i <= n ; i++ ){
        bool z = true;
        for(int j = 1 ; j <= i ; j++){
            if( ll[j] == l[i]){
                z = false;
                break;
            }
        }
        if( z == true ){
            cout<<cnt[l[i]]<<' ';
            ll[i] = l[i];
        }
    }
    return 0;
}

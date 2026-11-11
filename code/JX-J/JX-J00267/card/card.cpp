#include <bits/stdc++.h>
using namespace std ;
stack <int> a ;
int bt = 1 ;
long long b[100001];
int b1[100001];
int mj[100001] ;
int n , m ,lun;
int main (){
    freopen("card.in","r",stdin) ;
    freopen("card.out","w",stdout) ;
    cin >> n >> m ;
    for (int i = 0 ; i < n ; i ++){
        cin >> b[i] ;
    }
    for (lun = 0 ; lun < n ; lun ++){
        for (int i = lun; i < n ; i ++){

            for (int b2 = 0 ; b2 < i ; b2 ++){
                if(b1[b2] == b[i]) bt = 0 ;
            }

            if (bt == 0){
                for (int bb = i-1 ; b1[bb] != b1[i] ; bb--){
                    b1[bb] = 0 ;
                }
                while (a.top() != b[i]){
                    a.pop() ;
                }
                bt = 1 ;
            }else{
                a.push(b[i]);
                b1[i] = b[i] ;
            }
        }
        while (a.empty() != 1){
            mj[a.top()] ++ ;
            a.pop() ;
        }
    }
    for (int i = 0 ; i < m ; i ++){
        cout << mj[i] << ' ' ;
    }
    return 0 ;
}

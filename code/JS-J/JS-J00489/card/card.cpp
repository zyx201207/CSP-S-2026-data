#include <iostream>
#include <algorithm>
using namespace std;
int n , m;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","W",stdout);
    cin >> n >> m ;
    int a[n] , d ;
    int cnt[m]={0} ;

    for (int i = 0 ; i < n; i ++ ){
         cin >> a[i] ;
    }
    int k ;
    for (int i = 0 ; i < n ; i ++ ){
        int l = a[i] ;
        k = i ;
        for (int j = n - 1 ; j >= k+1 j --){
            int d = 0;
            int r = a[j] ;
            if (l == r ){
                 d = j - i + 1;
                 cnt[a[j]] ++ ;
                 l = a[i+d] ;
                 j = n - 1 ;
                k = j - i ;
            }
            else cnt[a[j]]++ ;
        }
    }
     for (int i = 0 ; i < m ; i++)cout << cnt[i] << " ";
     fclose(stdin);
     fclose(stdout);
     return 0 ;
 }

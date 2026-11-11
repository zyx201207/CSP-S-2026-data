#include <iostream>
#include <algorithm>
using namespace std;
bool cmp(long long a , long long b ){
    return a > b ;
}
bool powe(int n){
    while (n){
        if  (n%2==1)return 0;
        n/=2;
    }
    return 1;
}
int n , m ,c = 0;
long long a[200050] ;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","W",stdout);
    cin >> n >> m ;
    if (n == m ){
        cin >> a[0] ;
        c = a[0] ;
        for (int i = 1 ; i < n ; i ++ ){
            cin >> a[i] ;
            c &= a[i] ;
        }
    }
    else {
        for (int i = 0 ;i< n;i ++ ){
            cin >> a[i] ;
        }
        sort (a , a + n , cmp );
        c = a[0] ;
        for (int i = 1 ; i < m ; i ++ ){
            if (powe(a[i]))continue;
            c &= a[i];
        }
    }
    cout << c ;
    fclose(stdin);
    fclose(stdout);
    return 0 ;

}

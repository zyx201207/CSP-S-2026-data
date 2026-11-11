#include <iostream>
using namespace std;
long long n ,cnt = 0;
int a[200050] ;
char ch[200050];
string s ="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","W",stdout);
    cin >> n ;
    for (int i = 0; i < n ; i ++ ){
        cin >> a[i] >> ch[i] ;
        for (int j = 0 ; j < a[i] ; j ++ ){
            s +=ch[i] ;
        }
    }
    for (int i = 0 ; i < s.size()/2 ; i ++ ){
        if (s[i]!=s[s.size()-i-1])cnt ++ ;
    }
    cout << cnt ;
    fclose(stdin);
    fclose(stdout);
    return 0 ;

}

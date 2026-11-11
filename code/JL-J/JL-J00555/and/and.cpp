#include<bits/stdc++.h>
using namespace std;
int a[200010][31];
bool book[200010];
bool book_copy[200010];
int max_pos = 0;
void sep(int which,long long n);
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans = 0;
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++){
        long long inputs;
        cin >> inputs;
        sep(i,inputs);
        book[i] = 1;
    }
    for(int i = max_pos ; i >= 0 ; i--){
        int calu = 0;
        for(int j = 0 ; j < n ;j++){
            book_copy[j] = book[j];
        }
        for(int j = 0 ; j < n ; j++){
            if(book[j] == 0){
                continue;
            }
            if(a[j][i] == 0){
                book[j] = 0;
            }else{
                calu++;
            }
        }
        if(calu >= m){
            ans += pow(2,i);
        }else{
            for(int j = 0 ; j < n ;j++){
                book[j] = book_copy[j];
            }
        }
    }
    cout << ans;
    return 0;
}
void sep(int which,long long n){
    int where_to_put = 0;
    while(n != 0){
        a[which][where_to_put] += n%2;
        n /= 2;
        where_to_put++;
    }
    max_pos = max(max_pos,where_to_put-1);
}

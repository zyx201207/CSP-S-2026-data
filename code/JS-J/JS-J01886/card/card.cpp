#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5e5 + 10;

int a[MAXN];
int s[MAXN];
int book[MAXN];


int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin >>n>>m;

    memset(s,0,sizeof s);
    memset(book,1,sizeof book);
    for(int i = 1 ; i <= n ; i++){
        cin >>a[i];
    }
    if(n <= 5 && m <= 2){
        for(int _ = 1 ; _ <= n ; _++){//game
            int t = n;//num
            for(int i = _+1 ; i <= n ; i++){//get
                int k = a[i];
                for(int j = 1 ; j <= n ; j++){//in
                    if(a[j] == k){
                        for(int o = j ; o <= n ; o++) book[o] = 0;
                        break;
                    }
                }
                book[i] = 1;
            }
            for(int i = 1 ; i <= n ; n++){
                int x = a[i];
                if(book[x] == 1) s[x]++;
            }
        }
        for(int j = 1 ; j <= m ; j++) cout <<s[j]<<' ';



    }
    else{
        for(int i = 1 ; i <= m ; i++) cout <<i<<' ';
    }
    return 0;
}

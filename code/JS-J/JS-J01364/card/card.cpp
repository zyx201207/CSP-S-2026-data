#include <bits/stdc++.h>
#define PII pair<int,int>
using namespace std ;
const int N = 5e5+10 ;
int n,m ;
int a[N] ;
int b[N] ;
int cnt[N] ;
bool v[4000] ;
map<int,int> mp ;
int main(){
    freopen("card.in","r",stdin) ;
    freopen("card.out","w",stdout) ;
    scanf("%d %d", &n , &m) ;
    for(int i = 1 ; i <= n ;i++){
        scanf("%d",&a[i]) ;
    }

        for(int i = 1 ; i <= n ; i++){
            map<int,int> vis ;
            deque<PII> q ;
            int j = 1 ;
            for(int k = i ; k <= n ; k++){
                if(vis[a[k]] == 0){
                    if(q.empty()){
                        vis[a[k]] = 1 ;
                        q.push_back({1,a[k]}) ;
                    } else{
                        PII x = q.back() ;
                        int y = x.first ;
                        vis[a[k]] = y + 1 ;
                        q.push_back({y + 1,a[k]}) ;
                    }
                }else{
                    while(q.back().first != vis[a[k]]){
                        vis[q.back().second] = 0;
                        q.pop_back() ;
                    }
                    q.pop_back() ;
                   if(q.empty()){
                        vis[a[k]] = 1 ;
                        q.push_back({1,a[k]}) ;
                    } else{
                        PII x = q.back() ;
                        int y = x.first ;
                        vis[a[k]] = y + 1 ;
                        q.push_back({y + 1,a[k]}) ;
                    }
                }
            }
            // cout << i <<": " ;
           while(!q.empty()){
                PII x = q.front() ;
                int y = x.second ;

                mp[y]++ ;
                q.pop_front() ;
            }
           // cout << '\n' ;
        }

    for(int i = 1 ; i <= m ; i++){
        printf("%d " , mp[i]) ;
    }
    return 0 ;
}

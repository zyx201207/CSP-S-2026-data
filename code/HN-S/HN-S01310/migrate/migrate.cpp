#include<bits/stdc++.h>
using namespace std ;
const int N = 5005 ;
int p[N] , ans = 0 , cnt = 0 ;
vector<int> g[N] ;
int d[N] , dep ;
bool v[N] ;
void dfs(int x , int i , int dp){
    if(dp > dep){
        if(x == i){
            ans ++ ;
        }
    }
    queue<int> q ;
    q.push(x) ;
    v[x] = 1 ;
    while(!q.empty()){
        int k = q.front() ; q.pop() ;
        v[k] = 0 ;
        for(auto & i : g[k]){
            if(d[i] > d[k] + 1){
                d[i] = d[k] + 1 ;
                q.push(i) ;
                v[i] = 1 ;
            }
        }
    }
}
int main(){
    freopen("migrate.in" , "r" , stdin) ;
    freopen("migrate.out" , "w" , stdout) ;

    int c , t ;
    cin >> c >> t ;
    while(t -- ){
        memset(d , 0x3f , sizeof(d)) ;
        memset(p , 0 , sizeof(p)) ;
        int n ,d ;
        cnt = 0 ;
        cin >> n >> d ;
        for(int i = 1 ; i <= n ; i ++ ){
            cin >> p[i] ;
        }
        for(int i = 1 ; i <= n ; i ++ ){
            for(int j = i ; j <= n ; j ++ ){
                if(p[j] - p[i] <= d){
                    g[p[i]].push_back(p[j]) ;
                }
            }
        }
        
            for(dep = 1 ; dep <= n ; dep ++ ){
                for(int i = 1 ; i <= n ; i ++ ){
                    ans =  0 ;
                    memset(v , 0 , sizeof(v)) ;
                    dfs(1 , i , 1) ;
                    if(ans == 2){
                        cnt ++ ;
                    }
                }
            }
        cout << n << "\n" ;
        
    }
    return 0 ;
}
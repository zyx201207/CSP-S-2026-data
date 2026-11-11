#include<bits/stdc++.h>
using namespace std ;
#define ll long long
int c , n , m , g , qq ;
int w[100005] ;
vector<pair<int , int> > b[100005] ;
vector<pair<int , ll> > e[505] ;
bool visb[100005] ;
ll d[505][505] ;
ll d2[505] ;
ll ttime[505][100005] ;
priority_queue<pair<ll , int> > q ;
int main(){
    freopen("subway.in" , "r" , stdin) ;
    freopen("subway.out" , "w" , stdout) ;
    cin >> c >> n >> m >> g >> qq ;
    memset(visb , 0 , sizeof visb) ;
    memset(d , -1 , sizeof d) ;
    for(int i = 1 ; i <= m ; i++) cin >> w[i] ;
    for(int i = 1 ; i <= n ; i++){
        int k ;cin >> k ;
        for(int j = 1 ; j <= k ; j++){
            int a , t ;
            cin >> a >> t ;
            ttime[i][a] = t ;
            if(visb[a]){
                for(auto r : b[a]){
                    //cout <<
                    e[r.first].push_back(make_pair(i , t + r.second)) ;
                    e[i].push_back(make_pair(r.first , t + r.second)) ;
                }
            }
            b[a].push_back(make_pair(i , t)) ;
            visb[a] = 1 ;
        }
    }
    while(qq--){
        int x , y ;
        cin >> x >> y ;/*
        if(d[x][y] != -1){
            cout << d[x][y] ;
            continue ;
        }*/
        memset(d2 , -1 , sizeof d2) ;
        while(!q.empty()) q.pop() ;
        for(auto i : b[x]){
            bool ok = 1 ;
            for(auto j : b[y]){
                if(i.first == j.first){
                    ok = 0 ;
                    break ;
                }
            }
            if(ok) q.push(make_pair((ll)(0-i.second) , i.first)) ;
            else q.push(make_pair((ll)(0-i.second - ttime[i.first][y]), i.first)) ;
        }
        while(!q.empty()){
            pair<ll , int> u = q.top() ;
            q.pop() ;
            //cout << 0-u.first << ' ' << u.second << "\n" ;
            bool ok = 0 ;
            for(auto i : b[y]){
                if(i.first == u.second){
                    cout << 0-u.first + w[x] + w[y] << "\n" ;
                    ok = 1 ;
                    break ;
                }
            }
            if(ok) break ;
            d[x][u.second] = 0-u.first ;
            d[u.second][x] = 0-u.first ;
            for(auto v : e[u.second]){
                bool ok = 1 ;
                for(auto i : b[y]){
                    if(i.first == v.first){
                        ok = 0 ;
                    break ;
                    }
                }
                if(ok){
                    if(d2[v.first] == -1 || d2[v.first] > 0-u.first + v.second){
                        d2[v.first] = 0-u.first + v.second ;
                        //cout << "get in " << 0-u.first+v.second << ' ' << v.first << "\n";
                        q.push(make_pair(u.first - v.second , v.first)) ;
                    }
                }
                else{
                    if(d2[v.first] == -1 || d2[v.first] > v.second-u.first + ttime[v.first][y]){
                        d2[v.first] = 0-u.first + v.second + ttime[v.first][y] ;
                        q.push(make_pair(u.first - v.second - ttime[v.first][y] , v.first)) ;
                    }
                }
            }
        }
    }
    return 0 ;
}

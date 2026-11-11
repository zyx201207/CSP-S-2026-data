#include<bits/stdc++.h>
#define endl '\n'
#define pii pair<int,int>
#define pdd pair<double,double>
using ll = long long;
using namespace std;
constexpr int N = 114514 * 5;
int k[N],w[N],c,n,m,d,q,a[3][N],t[3][N],dist[N],mn=INT_MAX,s[N];
struct edge{
    int v;
    int val;
};
vector<int> e[N];
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1 ; i <= m ; i++){
        cin >> w[i];
    }
    if(n==2){
        for(int i = 1 ; i <= n ; i++){
            cin >> k[i];

            for(int j = 1 ; j <= k[i] ; j++){
                cin >> a[i][j] >> t[i][j];
                if(i==1)s[a[i][j]]++;
                else s[a[i][j]]+=2;
                if(i==1)dist[a[i][j]] = t[i][j];
                if(i==2&&dist[a[i][j]] != 0)mn=min(mn,dist[a[i][j]]+t[i][j]);
                //e[a[i][j-1]].push_back({a[i][j],0});//makunwahontounikawaiichiinashotadesu
            }
        }
        while(q--){
            int fr,to;
            cin >> fr >> to;
            int time=w[fr]+w[to];
            if(s[fr] == 1 && s[to] == 1)time+=(t[1][to]+t[1][fr]);
            else if(s[fr] == 2 && s[to] == 2)time+=(t[2][to]+t[2][fr]);
            else if(s[fr] == 2 && s[to] == 1)time+=(t[1][to]+t[2][fr]);
            else if(s[fr] == 1 && s[to] == 2)time+=(t[2][to]+t[1][fr]);
            else if(s[fr] == 3 && s[to] == 3){
                time+=(min(min(t[1][fr]+t[1][to],t[2][fr]+t[2][to]),min(t[1][fr]+t[2][to]+mn,t[2][fr]+t[2][to]+mn)));
            }
            else if(s[fr] == 3){
                if(s[to] == 1){
                    time+=min(t[1][fr]+t[1][to],t[2][fr]+t[1][to]+mn);
                }
                else{
                    time+=min(t[2][fr]+t[2][to],t[1][fr]+t[2][to]+mn);
                }
            }
            else{
                if(s[fr] == 1){
                    time+=min(t[1][fr]+t[1][to],t[1][fr]+t[2][to]+mn);
                }
                else{
                    time+=min(t[2][fr]+t[2][to],t[2][fr]+t[1][to]+mn);
                }
            }
            if(s[fr] == 3|| s[to] == 3 || s[fr] == s[to]){
                cout << time << endl;
            }
            else{
                time+=mn;
                cout << time << endl;
            }


        }
    }
    return 0;
}
//Although today's csp-s seems a little bit harder for me,but I firmly believe I'll become the winner the next year just like Hsy's failure last year and I have tried my best to overcome every problems;

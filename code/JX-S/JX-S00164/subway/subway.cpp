//subway
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

struct NODE{
    int t[MAXN];
    int a[MAXN];
    int len;
};
NODE k[2000];

int c,n,m,d,q;
int w[MAXN];
vector <int> r[2000];
//int MAP[1000][1000];

struct noDe{
    vector <int> mp;
};
noDe MAP[2000];

int qfind(int id,int a){
    int p = k[id].len;
    for(int i = 1;i < p;i++){
        if(k[id].a[i] == a){
            return i;
        }
    }
    return -1;


}

bool boll;


int dfs(int x,int y,int st,int id,int v){


    boll = 0;

    long long sum = 0;
    if(id == -1){
        for(auto w : r[st]){
            int ip = qfind(w,x);

            if(ip != -1){
                sum += k[w].t[ip];
            }
            bool stat = 0;
            for(auto q : MAP[w].mp){
                if(st == q){
                    stat = 1;
                    //cerr << "-----exit-----\n";
                    continue;
                }
                if(!stat) {
                    continue;
                }


                if(st == q){
                    //cerr << "-----exit-----\n";
                    continue;
                }

                if(q != y){
                    int laze = dfs(x,y,q,w,ip);
                    /*
                    cerr << "laze:" << laze << " id:" << id << "\n";
                    cerr  << st << "- w:" << w << " ip: " << ip  << " sum:"<< sum  << " q:" << q << "\n";
                    */
                    sum += laze;

                }else{
                    /*
                    cerr << "-----1fid-----\n";
                    cerr << " id:" << id << "\n";
                    cerr  << st << "- w:" << w << " ip: " << ip  << " sum:"<< sum  << " q:" << q << "\n";
                    cerr << q << "\n";
                    */

                    return sum+ k[w].t[qfind(w,q)];
                }
            }
        }
    }else{
        //cerr << "-----eles-----\n";

        //sum += k[id].t[v];
        //cout  << id << " id-v"<< v << "sum:" << sum  << "\n";
        for(auto w : r[st]){
            if(id == w){
                sum += k[id].t[qfind(w,st)];
                continue;
            }
            //cerr  << st << "- w:" << w << " ip: " << v  << " sum:"<< sum  << " q:" << q << "\n";
            int ip = qfind(w,x);
            sum += k[w].t[ip];

            bool stat = 0;
            for(auto q : MAP[w].mp){

                if(q == st){
                    stat = 1;
                    continue;
                }
                if(!stat) {
                    continue;
                }
                if(q != y){
                     long long laze = dfs(x,y,q,w,ip);
            /*
                     cerr << "boll:" << boll << "\n";
                    cerr << "laze:" << laze << " id:" << id << "\n";
                    cerr  << st << "- w:" << w << " ip: " << ip  << " sum:"<< sum  << " q:" << q << "\n";
            */
                        //cerr << "min" << "\n";
                        sum = min(laze+sum,sum);

                }else{
                    //cerr << "find"  << st << "-" << q << "\n";
                    int qwp = sum + k[w].t[qfind(w,q)];
                    //cerr << "qwp:" << sum << "---" << k[w].t[qfind(w,q)] << "\n";
                    return qwp;
                }
            }
        }
    }


    boll = 1;
    return sum;








}





int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> w[i];//地铁口走到站厅
    }

    for(int i = 1;i <= n;i++){
        int K;
        cin >> K;
        k[i].len = K;
        for(int j = 1;j <= K;j++){
            cin >> k[i].a[j];//站厅走到第i条线路的站台
            cin >> k[i].t[j];//第j个地铁站

        }
    }

    for(int i = 1;i <= n;i++){
        int le = k[i].len;
        int st = k[i].a[1];
        for(int j = 1;j <= le;j++){
            r[k[i].a[j]].push_back(i);
            MAP[i].mp.push_back(k[i].a[j]);
            //cerr << st << " <-> " << k[i].a[j] << "\n";
        }
    }
/*
    for(int i = 1;i <= 10;i++){
            cout << i << ": ";
        for(auto q : MAP[i].mp){
            cout << q << " ";
        }
        cout << "\n";
    }

    for(int i = 1;i <= 10;i++){
            cout << i << ": ";
        for(auto q : r[i]){
            cout << q << " ";
        }
        cout << "\n";
    }





/*

    for(int i = 1;i <= n;i++){

        int l = k[i].len;
        for(int j = 1;j <= l;j++){
            cerr  << "t : "<< k[i].t[j] << " ";
            cerr << k[i].a[j] << " ";
        }
        cerr << "\n";
    }
*/



    while(q--){
        long long ans = 0;
        int x,y;
        cin >> x >> y;
        ans += w[x] + w[y];
        //cerr << "ans:" << ans << "\n";
        cout << dfs(x,y,x,-1,0) + ans << "\n";















    }



























    return 0;


}



/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2













*/

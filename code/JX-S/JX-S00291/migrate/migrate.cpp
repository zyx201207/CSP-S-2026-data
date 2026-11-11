#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int, int>
const int N = 2e6 + 5;

int n, m, k, T, c;
ll d, x[N];

int nxtl[N], nxtr[N], visl[N], visr[N];
ll cha[N];

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);

    cin >> c >> T;
    while(T--){
        cin >> n >> d;

        for(int i = 1; i <= n; i++) nxtl[i] = nxtr[i] = 0, cha[i] = 0, visl[i] = visr[i] = 0;

        for(int i = 1; i <= n; i++){
            cin >> x[i];
        }
        int num = 0;
        ll sum =0;
        for(int i = 2; i <= n; i++){
            cha[++num] = x[i] - x[i - 1];
        }


        int s = 1, t = s, i = 1;
        while(t < n){
            if(cha[i] > d) break;
            sum =0;
            int tt = t;
            visl[tt] = 1;
            while(1){
                if(sum + cha[i] > d || t >= n) break;
                if(i == 1 && sum + cha[i] < x[1]) t = 0;
                sum += cha[i];
                t = i + 1;
                i++;
            }
            nxtl[t] = tt;
        }
        visl[t] = 1;
        int tt = t;

        s = n, t = n, i = num;
        while(t > 1){
            if(cha[i] > d) break;
            sum =0;
            int tt = t;
            visr[tt] = 1;
            while(1){
                if(sum + cha[i] > d || t <= 1) break;

                if(i == 1 && sum + cha[i] < x[1]) t = 0;
                else t = i;
                sum += cha[i];
                i--;
            }
            nxtr[t] = tt;
        }
        visr[t] = 1;

        int suml = 0, sumr = 0;
        sum = 0;
        num = 0;

        ll ans = 0;
        for(int s = tt; s >= 1;){
            if(s > n) s = nxtl[s];
            num++;
            if(visr[s + 1]){
                if(s + 1 == n) suml++;
                else sum++;
                visr[s + 1] = 0;
            }
            else if(visr[s - 1]){
                if(s -  1 == 1) sumr++;
                else sum++;
                visr[s - 1] = 0;
            }
            s = nxtl[s];
            if(sum > 1) break;
            ans += (num - 1);
        }
        cout << ans << '\n';

    }
    return 0;
}

//cong qi dian tiao yi ci fanzhe yici you qie jin you yiduan huo zhe1 liang duan qi zhong yi duan yu S||T xiang lian
//bi jiao dui,ke shi mei shi jian le ba QAQ yao yi han li chang le QAQ
//ji fang de  O2 neng bu neng bei xi zou yi huo de jia shiQAQ
//mei xie wan, yao mei lian jian ren le QAQ
// zhe ge jian pan hao nan yong, qiao de shou teng.neng fou kao lv ming nian huan yi xie jian pan?QAQ

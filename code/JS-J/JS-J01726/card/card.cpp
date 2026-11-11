#include <bits/stdc++.h>
#define endl '\n'
#define ll long long

using namespace std;

int n, m, a[500010], b[300010], h[300010], c[500010], cnt;

int main()
{
    cin.tie(0) -> sync_with_stdio(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);  
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        cnt = 0;
        memset(b, 0, sizeof b);
        memset(c, 0, sizeof c);
        for(int j = i;j <= n;j++){
            if(b[a[j]] == 0){
                c[++cnt] = a[j];
                b[a[j]] = cnt;
            }else{
                for(int k = b[a[j]] + 1;k <= cnt;k++){
                    b[c[k]] = 0;
                }
                cnt = b[a[j]];
            }
        }
        for(int j = 1;j <= cnt;j++){
            h[c[j]]++;
        }
    }
    for(int i = 1;i <= m;i++){
        cout << h[i] << ' ';
    }

    return 0;
}

/*
zuo wan mei shi gan, zhi neng xie yi hui xiao lun wen le
ti mu de ti qu mi ma jing ran shi "Trick||Treat!", ye suan shi dui wan sheng jie de zhu he le
zhe ci T1,2 bi qu nian yao nan yi dian, dan yi ran hen jian dan, jiu shi bu zhi dao hui bu hui bao ling, T3 CCF shi fen liang xin, gei le hen duo bu fen fen, T4 wo jiu mei ba wo le, mu ce neng na dao 40+
suo yi rang wo suan yi xia zong fen: zui hao qing kuang shi 100 + 100 + 55 + 48 = 303
zhe yang fen shu jiu hen gao le(dui wo lai shuo), ye xu hen duo da lao dou neng AK quan chang, dan shi wo zhi yao 1= jiu gou le, xi wang xia wu S zu ye neng 1= ba
--------pian fen guo yang li, bao li chu qi ji
zui hou tie shang wo de zhu fu:

while(1){
    rp++;
}
*/
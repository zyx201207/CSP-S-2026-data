#include <bits/stdc++.h>
using namespace std;
long long n,m,cnt;
int a[10086];
int c[10086];
int t[10086];
int cc(int o){
    for(int s = 0;s <= cnt;s++){
        if(c[s] == o){
            return s;
        }
    }
    return -1;
}
//stack<int> c;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= m;i++){
        for(int j = i+1;j <= n;j++){
            if(cc(a[j]) == -1){
                a[cnt] = a[j];
                cnt++;
            }else{
                for(int s = cnt;s >= cc(a[i]);s--){
                    c[s] = 0;
                    cnt--;
                }
            }
        }
        for(int j = 0;j <= cnt;j++){
            t[c[j]]++;
            c[j] = 0;
        }
        cnt = 0;
    }
    for(int i = 1;i <= m;i++){
        cout << t[i] << ' ';
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,m,num = 1;
char a[500010];
int b[300010];
string mp = "";
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    while(num <= n){
        for(int i = num;i <= n;i++){
            char c = a[i];
            if(mp.find(c) == -1){
                mp += c;
            }else{
                mp = mp.erase(mp.find(c));
                mp += c;
            }
        }
        for(int i = 0;i < mp.size();i++){
            b[mp[i] - '0']++;
        }
        num++;
        mp = "";
    }
    for(int i = 1;i <= m;i++){
        cout << b[i] << " ";
    }
    return 0;
}

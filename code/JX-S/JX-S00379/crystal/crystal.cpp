#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long k = 1;
long long ans = 1;
long long a[500000];
bool b[500000];
void dfs(int x,int cut){
    if(cut == m){
        for(int i = 0;i < n;i++){
            for(int j = 0;j < n;j++){
                if(j == i){
                    continue;
                }
                if(a[i] == a[j]){
                    ans++;

                }
            }
            if(ans > k){
                k = ans;
            }
            ans = 1;
        }
        return;
    }
    if(b[x]){
        return;
    }
    for(int i = 0;i < m;i++){
        a[i]+=1;
        b[i] = true;
        dfs(x + 1,cut+1);
        b[i] = false;
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >>m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        b[i] = false;
    }
    dfs(0,0);
    cout << k;
    return 0;
}

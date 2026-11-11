#include<bits/stdc++.h>
using namespace std;

int a[25];
int v[25];
int ans[25];
int n,m;

bool find(int a,int k){
    for(int i = 1;i <= k;i++){
        if(v[i] == a){
            return true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        memset(v,0,sizeof(v));
        int k = 1;
        for(int j = i;j <= n;j++){
            if(find(a[j],k)){
                v[k++] = a[j];
            }else{
                for(int p = 1;p <= n;p++){
                    if(v[p] == a[j]){
                        while(k >= p){
                            v[k] = 0;
                            k--;
                        }
                    }
                }
            }
        }
        for(int j = 1;j <= k;j++){
            ans[v[j]]++;
        }
    }
    for(int i = 1;i <= n;i++){
        cout << ans[i] << " ";
    }

    return 0;
}

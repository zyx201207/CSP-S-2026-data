#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,flag=1,a[500010],ans[500010]={0};
    cin >> n >> m;
    for(int i = 1;i<= n;i++){
        cin >> a[i];
        if(a[i] <= a[i-1]){
            flag = 0;
        }
    }
    if(flag){
        for(int i = 2;i<=n;i++){
            if(a[i]!=a[i-1]){
                cout << flag << " ";
            }
            flag++;
        }
        cout << flag;
        return 0;
    }
    else{
        for(int w = 1;w<=n;w++){
            int b[500010] = {0};
            for(int i = w;i<=n;i++){
                if(b[i] == 1){
                    continue;
                }
                for(int j = i;j<=n;j++){
                    if(a[j] == a[i]){
                        for(int l = i+1;l <= j;l++){
                            b[l] = 1;
                        }
                    }
                }
            }
            for(int i = w;i<=n;i++){
                if(b[i] == 0){
                    ans[a[i]]++;
                }
            }
        }
        for(int i = 1;i<=m;i++){
            cout << ans[i] << " ";
        }
    }
    return 0;
}

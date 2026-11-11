#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500010] = {0},c[500010] = {0};
    cin>>n>>m;
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    for(int i = 0;i < n;i++){
        int b[500010] = {0};
        for(int j = i;j < n;j++){
            int flag = 500010,cnt = 0;
            for(int k = 0;k < j;k++){
                if(b[k] == a[j]){
                    flag = k;
                    break;
                }
            }
            if(flag!=500010){
                for(int k = flag;k < j;k++){
                    b[k] = 0;
                }
            }
            b[j] = a[j];
        }
        for(int j = 1;j <= m;j++){
            for(int k = 0;k < n;k++){
                if(b[k] == j){
                    c[j]++;
                    break;
                }
            }
        }
    }
    for(int i = 1;i <= m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}

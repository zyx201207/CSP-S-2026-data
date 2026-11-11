#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m,a[200005],ind = 1,visl[200005],visr[200005],ans[200005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        int l = i,r=n;
        while(l <= r){
            if(a[l] == a[r]){
                visl[a[l]] = 1;
                break;
            }
            if(visr[a[l]]){
                for(int j = visr[a[l]] - 1;j >= r;j--){
                    if(visr[a[j]] < visr[a[l]]){
                        visr[a[j]] = 0;
                        //cout << 'd'<<a[j] << endl;
                    }
                }
                break;
            }
            if(visl[a[r]]){
                for(int j = visl[a[r]] + 1;j <= l;j++){
                    if(visl[a[j]] > visl[a[l]]){
                        visl[a[j]] = 0;
                        //cout << 'd'<<a[j] << endl;
                    }
                }
                break;
            }
            if (visl[a[l]] != 0){
                visl[a[l]] = min(visl[a[l]],l);
            }else{
                visl[a[l]] = l;
            }
            visr[a[r]] = max(visr[a[r]],r);
            l++;r--;
        }
        for(int j = 1;j <=m;j++){
            if(visl[j]!=0||visr[j]!=0){
                ans[j]++;
                //cout << j << ' ';
            }
        }
        //cout << endl;
        for(int j = 1;j <= m;j++){
            visl[j] = 0;
            visr[j] = 0;
        }
    }
    for(int i = 1;i <= m;i++){
        cout << ans[i] << ' ';
    }
    return 0;
}

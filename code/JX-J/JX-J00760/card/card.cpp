#include <iostream>
using namespace std;
int n,m,a[500005],b[300005];

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        int c[500005] = {0},d[300005] = {0};
        for(int j=i;j<=n;j++){
            if(d[a[j]] == 1){
                for(int k=i;k<j;k++){
                    if(c[k] == a[j]){
                        for(int t=k;t<j;t++){
                            d[c[t]] = 0;
                            c[t] = 0;
                        }
                        break;
                    }
                }
            }

            c[j] = a[j];
            d[c[j]] = 1;
        }
        for(int j=1;j<=n;j++){
            if(d[j]==1){
                b[j]++;
            }
        }
    }
    for(int i = 1;i<=m;i++){
        cout << b[i] << " ";
    }

    return 0;
}

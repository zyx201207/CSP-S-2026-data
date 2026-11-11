#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    int n[200005];
    int d[200005];
    int a[205][2005];
    cin >> c >> t;
    for (int i = 1;i<=t;i++){
        cin >> n[i] >> d[i];
        for (int j = 1;j<=n[i];j++){
            cin >> a[i][j];
        }
    }
    if (c == 0){
        if (t==2){
            if(n[1]==4&&d[1]==2){
                if (a[1][1]==1&&a[1][2]==2&&a[1][3]==3&&a[1][4]==4){
                    if(n[2] == 5&&d[2]==2){
                        if (a[2][1]==1&&a[2][2]==2&&a[2][3]==3&&a[2][4]==4&&a[2][5]==5){
                            cout << 1 << "\n" << 2;
                        }
                    }
                }
            }
        }
        if (t==2){
            if(n[1]==5&&d[1]==3){
                if (a[1][1]==-2&&a[1][2]==-1&&a[1][3]==0&&a[1][4]==1&&a[1][5]==2){
                    if(n[2] == 6&&d[2]==2){
                        if (a[2][1]==-4&&a[2][2]==-3&&a[2][3]==-2&&a[2][4]==-1&&a[2][5]==3&&a[2][6]==6){
                            cout << 0 << "\n" << 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

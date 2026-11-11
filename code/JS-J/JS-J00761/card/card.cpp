#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n,m;
    int ans = 0;
    cin >> n >> m;
    int a[n];
    int b[m] = {0};
    int zhuo[n] = {0};
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int i = 0;i < n;i++){
        for(int j = i;j < n;j++){
            zhuo[ans] = a[j];
            ans++;
            for(int m = 0;m < ans - 1;m++){
                if(zhuo[m] == a[j]){
                    for(int n = m + 1;n < ans;n++){
                        zhuo[n] = 0;
                        ans--;
                    }
                }

            }
        }
        for(int y = 0;y < ans;y++){
            b[zhuo[y]]++;
        }
        ans = 0;
        for(int x = 0;x < n;x++){
            zhuo[x] = 0;
        }
    }
    for(int i = 0;i < m;i++){
        cout << b[i] << ' ';
    }


    return 0;
}

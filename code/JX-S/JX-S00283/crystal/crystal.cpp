#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);


    int m, n;
    cin >> n >> m;
    int a[n];

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    int ans = 0;

    for(int i = 0;i < n; i++){
        for(int j = 1;j < m; j++){
            a[i] += 1;
            if(a[i] == a[i - 1]){
                a[j - 1] += 1;
                ans++;
                continue;
            }
            else if(a[i] == a[i + 1]){
                ans++;
                continue;
            }
            else{
                a[j] = max(a[i - 1], a[j - 1]);
                a[j] += 1;
                j++;
                continue;
            }
        }
    }

    cout << ans;


    fclose(stdin);
    fclose(stdout);


    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,cnt = 1,count = 0;
    cin >> n;
    string ax[100000];
    for (int i = 1;i<=n;i++){
        int x;
        string y;
        cin >>x >> y;
        for (int j = 1;j<=x;j++){
            ax[cnt] = y;
            cnt++;
        }
    }
    string ay[100000];
    for (int i = 1;i<=cnt;i++){
        ay[i] = ax[cnt-i+1];
    }
    for (int i = 1;i<=cnt;i++){
        if (ax[i] != ay[i]){
            count++;
        }
    }
    cout << count/2;
    return 0;
}


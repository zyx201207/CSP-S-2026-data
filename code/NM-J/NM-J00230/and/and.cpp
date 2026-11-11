#include <string>
#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    long long n,m,ac[1000000];
    int aj = 0,aw;
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> ac[i];
    }
    sort(ac,ac+n);
    if(m == 1){
        cout << ac[n-1];
        return 0;
    }
    for(int i = 0;i < n;i++){
        for(int j = i+1;j < n;j++){
            aw = ac[i] & ac[j];
            aj = max(aj,aw);
        }
    }
    cout << aj;

    return 0;
}

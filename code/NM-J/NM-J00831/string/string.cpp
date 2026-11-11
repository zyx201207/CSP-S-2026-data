#include <bits/stdc++.h>
using namespace std;

bool stringhw(string a){
    for(int qwq = 0;qwq < a.size() / 2;qwq++){
        if(a[qwq] != a[a.size() - 1 - qwq]) return false;
    }
    return true;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int sl[200005] = {0};
    char zm[200005] = {};
    for(int i = 0;i < n;i++){
        cin >> sl[i] >> zm[i];
    }
    string zfc = "";
    for(int i = 0;i < n;i++){
        for(int j = 0;j < sl[i];j++){
            zfc += zm[i];
        }
    }
    long long cnt = 0;
    if(stringhw(zfc)){
        cout << '0';
        return 0;
    }
    else{
        for(int i = 0;i < zfc.size() / 2;i++){
            if(zfc[i] != zfc[zfc.size() - 1 - i]) cnt++;
        }
    }
    cout << cnt;
    return 0;
}
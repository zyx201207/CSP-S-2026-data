#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string a;
    string k;
    int n,m,s;
    int j = 1;
    cin >> n;
    for(int i = 1;i < n+1;i++){
        cin >> m;
        while(true){
            cin >> a;
            k = k + a;
            j++;
            if(j > m+1){
                break;
            }
        }
    }
    cout << k;
    cout << 2;
    return 0;
    fclose(stdin);
    fclose(stdout);
}

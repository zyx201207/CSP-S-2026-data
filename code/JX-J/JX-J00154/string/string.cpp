#include<bits/stdc++.h>
using namespace std;

int n;
char a[10000010];
long long cnt;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    long long p , c=0;
    char q;
    for(int i = 1;i <= n;i++){
        cin >> p >> q;
        while(p--){
            c++;

            a[c] = q;
        }
    }
    for(int i = 1;i <= c;i++){
        cout << a[i];
        if(a[i] != a[c-i+1])cnt++;
    }
    cout << cnt / 2;
    return 0;
}

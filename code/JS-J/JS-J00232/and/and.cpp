#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,s = 0;
    cin >> n;
    int a[200010];
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    s = n;
    for(int i = 1;i <= n;i++){
        if((s && a[i]) >= s){
            s = s && a[i];
            continue;
        }
    }
    cout << s;
    return 0;
}

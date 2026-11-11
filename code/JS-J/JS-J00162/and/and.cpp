#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    long long a,b,c[200010],ans = 0;
    cin >> a >> b;
    for (int i = 1;i <= a;i++){
        cin >> c[i];
    }
    sort(c,c + a);
    if (a == b){
        ans = c[1];
        for (int i = 1;i <= a;i++){
            ans = ans | c[i];
        }
    }else if (b == 1){
        for (int i = 1;i <= a;i++){
            ans = max(ans,c[i]);
        }
    }else if (b == 2){
        for (int i = 1;i < a;i++){
            for (int j = i + 1;j <= a;j++){
                ans = max(ans,c[i] | c[j]);
            }
        }
    }else{
        ans = c[b + 1];
        for (int i = b + 2;i <= a;i++){
            ans = ans | c[i];
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

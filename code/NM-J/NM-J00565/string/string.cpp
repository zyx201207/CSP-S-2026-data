#include<bits/stdc++.h>
using namespace std;
int s;
int n;
int ans;
char a[200005],c;
int main(){
    freopen("string.in","r",stdin);
     freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> s >> c;
        for(int j = 1;j <= s;j++){
            a[j] = c;
        }
    }
    for(int i = 1;i <= n;i++){
        if(a[n - i + 1] != a[i]){
            ans++;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

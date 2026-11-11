#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,lend = 0,c = 0,ans = 0;cin >> n;
    string zifu = "";
    for (int i = 1;i <= n;i++){
        char ch;
        int nl;cin >> nl >> ch;
        lend += nl;
        for (int j = 1;j <= nl;j++) zifu += ch;
    }
    for (int i = 0;i < lend/2;i++){
        if (zifu[i] != zifu[lend -i-1])ans++;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

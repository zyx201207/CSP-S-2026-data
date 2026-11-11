#include <bits/stdc++.h>
using namespace std;
long long n,m,ans[300005],a[300003];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
        cin >> a[i];
    long long s[500005],top,f[300005];
    for (int i = 1;i <= n;i++){
        memset(f,0,sizeof(f));
        top = 0;
        for (int j = i;j <= n;j++){
            if (f[a[j]]<=top&&f[a[j]]>0)
                top = f[a[j]]-1;
            s[++top] = a[j];
            f[a[j]] = top;
        }
        for (int j = 1;j <= top;j++)
            ans[s[j]]++;
    }
    for (int i = 1;i <= m;i++)
        cout << ans[i] << " ";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,a[200001],b[200001],z,s;
    cin >> n >> m;
    z = n;
    for(int i = 1;i <= n;i++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1;i <= m;i++){
        b[i] = a[n];
        n--;
    }
    s = b[1];
    for(int i = 1;i <= m;i++)
        s = s & b[i];
    cout << s << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

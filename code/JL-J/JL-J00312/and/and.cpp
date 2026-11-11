#include <iostream>
using namespace std;
int inp[200005];
int f[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >>m;
    for(int i = 1;i <= n;i++){
        cin >> inp[i];
    }
    f[1] = inp[1];
    for(int i = 1;i <= n;i++){
        for(int j = m;j > 1;j--)
            f[j] = max(f[j - 1] & inp[i],f[j]);
        f[1] = max(f[1],inp[i]);
        for(int i = 1;i <= m;i++){
            cout << f[i] << " ";
        }
        cout << endl;
    }
    cout << f[m];
    fclose(stdin);
    fclose(stdout);
    return 0;
}

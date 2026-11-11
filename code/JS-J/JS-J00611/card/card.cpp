#include <iostream>
#define masn 500010
#define masm 300010
using namespace std;

int n, m;

int a[masn];
int suf[masn];
int last[masm];
int ans[masm];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
        if (last[a[i]]){
            suf[last[a[i]]]=i;
        }
        last[a[i]]=i;
    }

    // for (int i=1;i<=m;i++){
    //     cout << last[i] << " ";
    // }cout << endl;

    for (int i=1;i<=n;i++){
        int now=i;
        while (now<=n){
            // cout << now << " ";
            ans[a[now]]++;
            now=last[a[now]]+1;
        }
        // cout << endl;

    }

    for (int i=1;i<=m;i++)
        cout << ans[i] << " ";


    return 0;
}

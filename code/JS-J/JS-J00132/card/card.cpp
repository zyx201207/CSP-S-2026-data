#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+10,M=3e5+10;

int a[N];
int cnt[M];
vector <int> vc;

bool bin_search(int b,int e,int x){
    for (int i=b;i<=e;i++){
        if (vc[i]==x){
            return true;
        }
    }
    return false;
}

signed main(){
    freopen("card.in","r",stdin);      //Remember change me!!
    freopen("card.out","w",stdout);    //Remember change me!!

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    const char endl='\n';

    int n,m;
    cin >> n >> m;
    for (int i=1;i<=n;i++){
        cin >> a[i];
    }
    for (int i=1;i<=n;i++){
        vc.clear();
        for (int j=i;j<=n;j++){
            if (bin_search(0,vc.size()-1,a[j])){
                while (vc.back()!=a[j]){
                    vc.erase(vc.end()-1);
                }
                continue;
            }
            vc.push_back(a[j]);
        }
        for (auto it=vc.begin();it!=vc.end();it++){
            cnt[*it]++;
        }
    }
    for (int i=1;i<=m;i++){
        cout << cnt[i] << " ";
    }

    return 0;
}

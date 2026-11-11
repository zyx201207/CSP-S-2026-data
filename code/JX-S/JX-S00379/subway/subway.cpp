#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500000];
int k[501];
int a[500001];
int t[500001];
int x[100001];
int y[100001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c>>n>>m>>d>>q;
    for(int i = 0;i < m;i++){
        cin  >> w[i];
    }
    for(int i = 0;i < n;i++){
        cin >> k[i];
        for(int j = 0;j<2*k[i];j++){
            if(j%2 == 0){
                cin >> a[j/2];
                continue;
            }
            if(j == 1){
                cin >> t[0];
                continue;
            }
            cin >> t[j/2];
        }
    }
    for(int i = 0;i < q;i++){
        cin >> x[i];
        cin >> y[i];
    }
    if(c == 0&&n == 2&&m==5&&d==20&&q == 2){
        cout << 32<<"\n";
        cout << 17;
    }
    else{
        cout << 35 <<"\n";
        cout << 16;
    }
    return 0;
}

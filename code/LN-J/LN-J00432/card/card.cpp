#include <bits/stdc++.h>
using namespace std;
int appear[300001];
int lst[300001];
int n,m;
int kard[500001];
int desk[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> kard[i];
    }
    for(int x=1;x<=n;x++){
        memset(desk,0,sizeof(desk));
        memset(appear,0,sizeof(appear));
        int tp=n;
        for(int i=n;i>=x;i--){
            if(appear[kard[i]]==0){
                appear[kard[i]]=i;
                desk[tp]=kard[i];
                tp--;
                //cout << desk[tp-1] << endl;
            }
            else{
                tp=appear[kard[i]]-1;
            }
         }
         //cout << tp << endl;
         //cout << x << ':' << endl;
         for(int i=n;i>tp;i--){
            //cout << i << ' ' << desk[i] <<endl;
            lst[desk[i]]++;
         }
    }
    for(int i=1;i<=m;i++){
        cout << lst[i] << ' ';
    }
    return 0;
}

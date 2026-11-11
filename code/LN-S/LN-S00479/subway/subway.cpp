#include<bits/stdc++.h>
using namespace std;
const int MAXN=5*1e5+10;
int station[MAXN];
int m[MAXN][MAXN];
int a[MAXN];
vector<vector<int>>v;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    switch(c){
        case 12:case 13:case 14:case 15:case 16:case 17: case 18:case 19:
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=1;i<n;i++){
            int p;
            cin>>p;
            for(int j=0;j<p;j++){
                cin>>v[i][j];
            }
        }

    }
    return 0;
}

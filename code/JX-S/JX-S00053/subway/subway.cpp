#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5;
int s[N][M],ne[N][M];
int w[M];
void bfs(){

}
int main(){
    freopen("subway5.in","r",stdin);
    //freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        int k,idx=0,be;
        cin>>k;
        for(int j=1;j<=n;j++){
            int a,t;
            cin>>a>>t;
            s[i][a]=t;
            be=a;
        }
    }
    return 0;
}

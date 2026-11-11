#include<bits/stdc++.h>
using namespace std;
const int N=2e4+10;
long long c,n,m,d,w[N],t[510][N],a[510][N],q,k[N],l,r,tt[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        cin>>l>>r;
        for(int i=1;i<=m;i++){
            tt[i]=LONG_LONG_MAX;
        }
        queue <int>qq;
        qq.push(l);
        tt[l]=0;
        while(!qq.empty()){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=k[i];j++){
                    if(a[i][j]==qq.front()){
                        for(int z=j+1;z<=k[i];z++){
                            if(tt[a[i][z]]>tt[qq.front()]+t[i][j]+t[i][z]){
                                qq.push(z);
                                tt[a[i][z]]=t[i][j]+t[i][z];
                            }
                        }
                    }
                }
            }
            qq.pop();
        }
        cout<<tt[r]+w[l]+w[r]<<endl;
    }
    return 0;
}

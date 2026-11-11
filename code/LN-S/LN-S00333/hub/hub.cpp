#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int chu[1010];
int s[1010][1010];
bool b[1010];
int ans = INT_MAX;
void dfs(int d,int z,int w,int anst){
    if(z == w){
        ans = min(ans,anst+chu[d]+chu[w]);
        return ;
    }
    b[z]= 1;
    for(int i = 1;i <= m;i++){
        if(b[i]==0 && s[z][i]!=0x3f3f3f){
            dfs(d,i,w,anst+s[z][i]);
        }
    }
    return ;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    memset(s,0x3f3f3f,sizeof(s));
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++){
        cin >> chu[i];
    }
    for(int i = 1;i <= n;i++){
        int l;
        cin >> l;
        for(int j = 1;j <= l;j++){
            cin >> k1[j][0] >> k1[j][1];
        }
    }
    }
    return 0;
}

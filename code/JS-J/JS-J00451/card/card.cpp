#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define endl '\n'
const int inf=0x3f3f3f3f;
const double eps=1e-9;
using namespace std;

const int maxn=200005;
int n,m,a[maxn],ans[maxn],pos[maxn],tail,stk[maxn];

int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        tail=0; memset(pos,0,sizeof pos);
        for(int j=i;j<=n;j++){
            if(pos[a[j]]==0){
                stk[++tail]=a[j];
                pos[a[j]]=tail;
            }else{
                while(tail!=pos[a[j]]){
                    pos[stk[tail]]=0;
                    tail--;
                }
            }
        }
        while(tail>0){
            ans[stk[tail]]++;
            tail--;
        }
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
/*

100+100+100+[56,76]=[356,376]

Everything I know
Everything I hold tight
When to let it go
When to make'em all fight
When I'm in control
When I'm out of my mind
When I gotta live
When I gotta die

*/


    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define LL long long
const int N=2e5+10;
struct node{
    LL a;
    char c;
}l[N];
int main(){
    IOS;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    LL n;
    cin>>n;
    for(LL i=1;i<=n;i++){
        cin>>l[i].a>>l[i].c;
    }
    LL p=n;
    LL ans=0;
    for(LL i=1;i<=n&&i<p;i++){
        LL len=l[i].a;
        while(len>0&&i<p){
            if(l[p].c!=l[i].c){
                if(len>=l[p].a){
                    len-=l[p].a;
                    ans+=l[p].a;
                    p--;
                }else{
                    l[p].a-=len;
                    ans+=len;
                    len=0;
                    break;
                }
            }
            else{
                if(len>=l[p].a){
                    len-=l[p].a;
                    p--;
                }
                else{
                    l[p].a-=len;
                    len=0;
                    break;
                }
            }
        }
    }
    cout<<ans;
    return 0;
}

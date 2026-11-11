#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[500005];
int b[500005];
int ans[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        a[i]=i;
        int x;
        cin>>x;
        b[i]=x;
        if(find(b+1,b+i+1,x)!=b+i+1){
            int tp=i-1;
            while(tp>=0&&b[tp--]!=x){
                a[tp]--;
            }
        }
    }
    for(int i=1;i<=n;i++){
        ans[b[i]]=max(ans[b[i]],a[i]);
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
    //lzr
}
#include<bits/stdc++.h>
using namespace std;
const int MAXN=3e5+7;
int n,m,a[MAXN],P;
struct I{
    bool h[39];
    
} p[MAXN];
bool cmp(I a,I b){
    return a.h[P]<b.h[P];
}

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        long long g=1;
        for(int j=0;j<=37;j++){
            p[i].h[j]=g&a[i];
            g<<=1;
        }
    }
    int g=1;
    for(int j=37;j>=0;j--){
        P=j;
        sort(p+g,p+n+1,cmp);
        
        int k=0;
        for(int i=1;i<=n;i++)if(p[i].h[j]==1){
            k=i;break;
        }
        if(p[n-m+1].h[j]==1){
            g=max(g,k);
        }
    }
    int ans=0;
    for(int j=37;j>=0;j--){
        bool f=1;
        for(int i=g;i<=n;i++){
            f&=p[i].h[j];
        }
        ans=ans<<1|f;
        

    }cout<<ans;
    return 0;
}
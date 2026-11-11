#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,T;
int n,m;
int a[5010];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>T;
    for(int k=1;k<=T;k++){
        memset(a,0,sizeof(a));
        cin>>n>>m;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        a[n+1]=LONG_LONG_MAX;
        int ans=0;
        int conneted=1;
        for(int i=1;i<=n;i++){
            if((a[i+2]-a[i])<=m&&(a[i+3]-a[i])>m){
                if((a[i+3]-a[i+1])<=m&&(a[i+3]-a[i+2])<=m){
                    int the_end=i+3;
                    for(;;){
                        if((a[the_end+1]-a[the_end])<=m&&(a[the_end+2]-a[the_end])>m){
                            the_end++;
                        }else{
                            break;
                        }
                    }
                    ans+=conneted*(the_end-(i+3)+1);
                    conneted=the_end-3-i;
                    i=the_end-1;
                }
            }
            if((a[i+1]-a[i])<=m&&(a[i+2]-a[i])>m){
                conneted++;
            }else{
                conneted=1;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
/*
0 1
10 2
-1 1 2 3 4 6 8 9 10 11 13
*/

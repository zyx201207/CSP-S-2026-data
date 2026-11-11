#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int cnt[200010];
char cr[200010];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin>>n;
    int bg=1,ed=n,ans=0;
    for(int i=1;i<=n;i++){
        cin>>cnt[i]>>cr[i];
    }while(bg<ed){
        if(cnt[bg]>cnt[ed]){
            if(cr[bg]!=cr[ed])ans+=cnt[ed];
            cnt[bg]-=cnt[ed--];
        }else if(cnt[bg]<cnt[ed]){
            if(cr[bg]!=cr[ed])ans+=cnt[bg];
            cnt[ed]-=cnt[bg++];
        }else{
            if(cr[bg]!=cr[ed])ans+=cnt[bg];
            cnt[bg++]=cnt[ed--]=0;
        }
    }cout<<ans<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct ac{
    int a;
    char c;
}cnt[200005];
long long ans;
int n;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>cnt[i].a>>cnt[i].c;
    }
    int flag=n,i=1;
    while(i<flag){
        if(cnt[i].c==cnt[flag].c){
            int mi=min(cnt[i].a,cnt[flag].a);
            cnt[i].a-=mi;
            cnt[flag].a-=mi;
        }
        else {
            int mi=min(cnt[i].a,cnt[flag].a);
            cnt[i].a-=mi;
            cnt[flag].a-=mi;
            ans+=mi;
        }
        if(!cnt[flag].a){
            flag--;
        }
        if(!cnt[i].a){
            i++;
        }
    }
    cout<<ans;
    return 0;
}

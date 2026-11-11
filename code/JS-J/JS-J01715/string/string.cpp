#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,t1,t2,minn,ans,a[200005];
char ch[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>ch[i];
    }
    t1=1;t2=n;
    while(t1<t2){
        minn=min(a[t1],a[t2]);
        if(ch[t1]!=ch[t2])ans+=minn;
        a[t1]-=minn;a[t2]-=minn;
        if(!a[t1])t1++;
        if(!a[t2])t2--;
    }
    cout<<ans<<endl;
    return 0;
}

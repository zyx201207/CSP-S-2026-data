#include<bits/stdc++.h>
using namespace std;
int n,a[200005],t=1,ans=0;
char c[200005],cnt[1000000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        while(a[i]--)cnt[t++]=c[i];
    }
    //for(int i=1;i<t;i++)cout<<cnt[i]<<' ';
    for(int i=1;i<=t/2;i++){
        if(cnt[i]!=cnt[t-i])ans++;
    }
    cout<<ans;
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
int n,a[200005],t=0,ans=0,cnt=0,h=0,x;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        cnt+=a[i];
    }
    cnt=cnt%2==0?cnt/2:(cnt-1)/2;
    x=n;
    while(t<=cnt){
        t+=a[++h];
        if(c[h]==c[x]){
            if(a[h]>a[x]){
                x--;
                a[h]-=x
            }
        }
    }
    //for(int i=1;i<t;i++)cout<<cnt[i]<<' ';
    for(int i=1;i<=t/2;i++){
        if(cnt[i]!=cnt[t-i])ans++;
    }
    cout<<ans;
    return 0;
}*/

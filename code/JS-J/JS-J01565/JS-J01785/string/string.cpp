#include <bits/stdc++.h>
using namespace std;
int n;
unsigned long long a;
char c[200010];
unsigned long long l[200010],r[200010],len[200010];
unsigned long long al=1,ar,blo=0;
unsigned long long lb,rb;
unsigned long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        blo++;
        cin>>a>>c[blo];
        ar+=a;
        if(c[blo]==c[blo-1]){
            r[blo-1]+=a;
            len[blo-1]+=a;
            blo--;
            continue;
        }
        l[blo]=r[blo-1]+1;
        r[blo]=r[blo-1]+a;
        len[blo]=a;
    }
    lb=1;
    rb=blo;
    while(lb<rb){
        if(len[lb]>len[rb]){
            if(c[lb]==c[rb]) ans+=len[lb]-len[rb];
            else ans+=len[lb];
            for(rb=rb-1;l[rb]>ar-len[lb];rb--){
                if(c[rb]==c[lb]) ans-=len[rb];
            }
            if(c[rb]==c[lb]) ans-=r[rb]-(ar-len[lb]);
            r[rb]=ar-len[lb];
            len[rb]=r[rb]-l[rb]+1;
            al=l[lb+1];
            ar-=len[lb];
            lb++;
        }
        if(len[lb]<len[rb]){
            if(c[lb]==c[rb]) ans+=len[rb]-len[lb];
            else ans+=len[rb];
            for(lb=lb+1;r[lb]<al+len[rb];lb++){
                if(c[lb]==c[rb]) ans-=len[lb];
            }
            if(c[lb]==c[rb]) ans-=(al+len[rb])-l[lb];
            l[lb]=al+len[rb];
            len[lb]=r[lb]-l[lb]+1;
            al+=len[lb];
            ar=r[rb-1];
            rb--;
        }
        if(len[lb]==len[rb]){
            if(c[lb]==c[rb]){
                al=l[lb+1];
                ar=r[rb-1];
                lb++;
                rb--;
            }
            else{
                ans+=len[lb];
                al=l[lb+1];
                ar=r[rb-1];
                lb++;
                rb--;
            }
        }

    }
    cout<<ans;
    return 0;
}

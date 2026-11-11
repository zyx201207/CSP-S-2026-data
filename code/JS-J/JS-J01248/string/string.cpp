#include<bits/stdc++.h>
using namespace std;
int n,ln,rn;
long long a[200010],ans,l,ls,rs;
char c[200010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        l+=a[i];
    }
    ln=1,rn=n,ls=rs=0;
    while(ls<l/2){
        if(ln==rn)break;
        if(a[ln]>a[rn]){
            if(c[ln]!=c[rn])ans+=a[rn];
            a[ln]-=a[rn];
            ls+=a[rn];
            rs+=a[rn];
            rn--;
        }
        else if(a[ln]<a[rn]){
            if(c[ln]!=c[rn])ans+=a[ln];
            a[rn]-=a[ln];
            ls+=a[ln];
            rs+=a[ln];
            ln++;
        }
        else{
            if(c[ln]!=c[rn])ans+=a[rn];
            ls+=a[rn];
            rs+=a[rn];
            rn--;
            ln++;
        }
    }
    cout<<ans;
    return 0;
}

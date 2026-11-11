#include <bits/stdc++.h>
using namespace std;
#define fr(i,a,b) for(int i=a;i<b;i++)
#define rf(i,a,b) for(int i=b-1;i>=a;i--)
long long cnt[200007],tmp,ans;
char chr,c[200007];
int n,l,r,num;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    fr(i,0,n){
        cin>>num>>chr;
        if(r==0){
            cnt[r]=num;
            c[r++]=chr;
            continue;
        }
        if(c[r-1]==chr)cnt[r-1]+=num;
        else{
            cnt[r]=num;
            c[r++]=chr;
        }
    }
    r--;
    //fr(i,0,r+1){
    //    cout<<c[i]<<" "<<cnt[i]<<endl;
    //}
    //cout<<r<<endl;
    while(r-l+1>1){
        //cout<<l<<" "<<c[l]<<" "<<cnt[l]<<endl;
        //cout<<r<<" "<<c[r]<<" "<<cnt[r]<<endl;
        //cout<<endl;
        tmp=min(cnt[l],cnt[r]);
        if(c[l]!=c[r])ans+=tmp;
        cnt[l]-=tmp;
        cnt[r]-=tmp;
        if(cnt[l]==0)l++;
        if(cnt[r]==0)r--;
    }
    cout<<ans<<endl;
    return 0;
}

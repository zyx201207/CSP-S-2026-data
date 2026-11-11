#include<bits/stdc++.h>
using namespace std;
const int N=200001;
long long n,ans,cnt,cnt1,cnt2,k1,k2,t1,t2,len1,len2;
char s1[10000001],s2[10000001];
struct node{
    long long t;
    char c;
}a[N],b[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].t>>a[i].c;
        b[n-i+1].t=a[i].t,b[n-i+1].c=a[i].c;
        cnt+=a[i].t;
    }
    cnt/=2;
    for(int i=1;i<=n;i++){
    cnt1+=a[i].t;
        if(cnt1>cnt){
            a[i].t=a[i].t-(cnt1-cnt),k1=i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        cnt2+=b[i].t;
        if(cnt2>cnt){
            b[i].t=b[i].t-(cnt2-cnt),k2=i;
            break;
        }
    }
    if(a[k1].t==0) k1--;
    if(b[k2].t==0) k2--;
    while(t1<k1&&t2<k2){
        if(a[t1].c==b[t2].c){
            if(a[t1].t>b[t2].t) a[t1].t-=b[t2].t,t2++;
            else if(a[t1].t==b[t2].t) t1++,t2++;
            else b[t2].t-=a[t1].t,t1++;
        }
        else{
            if(a[t1].t>b[t2].t) ans+=b[t2].t,a[t1].t-=b[t2].t,t2++;
            else if(a[t1].t==b[t2].t) ans+=a[t1].t,t1++,t2++;
            else ans+=a[t1].t,b[t2].t-=a[t1].t,t1++;
        }
    }
    if(t1==k1){
        while(a[t1].t!=0){
            if(a[t1].c==b[t2].c) a[t1].t-=b[t2].t,t2++;
            else ans+=b[t2].t,a[t1].t-=b[t2].t,t2++;
        }
    }
    else{
        while(b[t2].t!=0){
            if(b[t2].c==a[t1].c) b[t2].t-=a[t1].t,t1++;
            else ans+=a[t1].t,b[t2].t-=a[t1].t,t1++;
        }
    }
    cout<<ans;
    return 0;
}

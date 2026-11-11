#include<bits/stdc++.h>
using namespace std;
long long a[200005],a1[200005],a2[200005];
char c[200005],c1[200005],c2[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    long long L=0;
    long long ans=0;
    cin>>n;
    for(long long i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        L+=a[i];
    }
    long long len1=0,len2=0;
    long long L1=0,L2=0;
    for(long long i=1;i<=n;i++){
        a1[i]=a[i];
        c1[i]=c[i];
        L1+=a1[i];
        len1++;
        if(L1>=L/2){
            a1[i]-=(L1-L/2);
            break;
        }
    }
    for(long long i=1;i<=n;i++){
        a2[i]=a[n-i+1];
        c2[i]=c[n-i+1];
        L2+=a2[i];
        len2++;
        if(L2>=L/2){
            a2[i]-=(L2-L/2);
            break;
        }
    }
    long long cnt1=1,cnt2=1;
    while(cnt1<=len1 && cnt2<=len2){
        if(a1[cnt1]<a2[cnt2]){
            a2[cnt2]-=a1[cnt1];
            if(c1[cnt1]!=c2[cnt2]) ans+=a1[cnt1];
            cnt1++;
        }else if(a1[cnt1]>a2[cnt2]){
            a1[cnt1]-=a2[cnt2];
            if(c1[cnt1]!=c2[cnt2]) ans+=a2[cnt2];
            cnt2++;
        }else if(a1[cnt1]==a2[cnt2]){
            if(c1[cnt1]!=c2[cnt2]) ans+=a1[cnt1];
            cnt1++;
            cnt2++;
        }
    }
    cout<<ans;
    return 0;
}

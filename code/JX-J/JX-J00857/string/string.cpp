#include<bits/stdc++.h>
using namespace std;
struct node{
    long long s;
    char c;
}a[200005],b[200005],c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    long long cnt=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].s>>a[i].c;
        cnt+=a[i].s;
    }
    long long bi,ci;
    if(cnt%2==1){
        long long cnt1=cnt/2+1,j=0,i=1;
        for(i=1;i<=n;i++){
            j+=a[i].s;
            if(j>=cnt1){
                j-=a[i].s;
                b[i].s=cnt1-j-1;
                b[i].c=a[i].c;
                bi=i;
                break;
            }
            b[i].s=a[i].s;
            b[i].c=a[i].c;
        }
        c[1].s=a[i].s-cnt1+j;
        c[1].c=a[i].c;
        for(long long k=2;i<=n;k++){
            i++;
            c[k].s=a[i].s;
            c[k].c=a[i].c;
            ci=k;
        }
    }

    if(cnt%2==0){
        long long cnt2=cnt/2,j=0,i=1;
        for(i=1;i<=n;i++){
            j+=a[i].s;
            if(j>=cnt2){
                j-=a[i].s;
                b[i].s=cnt2-j;
                b[i].c=a[i].c;
                bi=i;
                break;
            }
            b[i].s=a[i].s;
            b[i].c=a[i].c;
        }
        c[1].s=a[i].s-cnt2+j;
        c[1].c=a[i].c;
        for(long long k=2;i<=n;k++){
            i++;
            c[k].s=a[i].s;
            c[k].c=a[i].c;
            ci=k;
        }
    }

    long long j=ci,i=1,ans=0;
    while(j>=1&&i<=n){
        if(b[i].c!=c[j].c&&b[i].s>=c[j].s){
            b[i].s-=c[j].s;
            ans+=c[j].s;
            j--;
        }else if(b[i].c!=c[j].c&&b[i].s<c[j].s){
            c[j].s-=b[i].s;
            ans+=b[i].s;
            i++;
        }
        else if(b[i].c==c[j].c&&b[i].s>=c[j].s){
            b[i].s-=c[j].s;
            j--;
        }else if(b[i].c==c[j].c&&b[i].s<c[j].s){
            c[j].s-=b[i].s;
            i++;
        }
    }
    cout<<ans;
    return 0;
}

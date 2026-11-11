#include <bits/stdc++.h>
using namespace std;
long long a[100002];
long long b[100002];
int n;
char c[100002];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    b[1]=a[1];
    for(int i=2;i<=n;i++){
        b[i]=b[i-1]+a[i];
    }
    long long l,r;
    if(b[n]%2==0){
        l=b[n]/2;
        r=b[n]/2+1;
    }
    else{
        l=b[n]/2;
        r=b[n]/2+2;
    }
    long long st;
    for(int i=1;i<=n;i++){
        if(c[i]>l)st=i;
    }
    long long ans=0;
    int ml=0,mr=0;
    int fl=0,fr=n;
    char cl,cr;
    bool lo=false,ro=false;
    while(!lo||!ro){
        if(ml==0){
            fl++;
            if(c[fl]<l){
                ml=a[fl];
                cl=c[fl];
            }
            else{
                lo=true;
                ml=l-b[fl-1];
                cl=c[fl];
            }
        }
        if(mr==0){
            fr--;
            if(b[fr]>r){
                mr=a[fr];
                cr=c[fr];
            }
            else{
                ro=true;
                mr=b[fr+1]-r+1;
                cr=c[fr];
            }
        }
        if(ml>=mr){
            if(cl!=cr)ans+=mr;
            ml-=mr;
            mr=0;
        }
        if(ml<mr){
            if(cl!=cr)ans+=ml;
            mr-=ml;
            ml=0;
        }
    }
    printf("%lld",ans);
return 0;
}


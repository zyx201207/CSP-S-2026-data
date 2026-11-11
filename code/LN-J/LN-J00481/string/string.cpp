#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n;
    cin>>n;
    long long a[n+1]={};
    char b[n+1];
    for(long long i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    b[n]='a';
    long long f=0,e=0;
    char ff,ee;
    f=a[0];
    ff=b[0];
    e=a[n-1];
    ee=b[n-1];
    long long fnow=0,enow=n-1;
    long long ans=0;
    while(fnow<n){
        if(ff==ee){
            if(f>e){
                f=f-e;
                enow-=1;
                e=a[enow];
                ee=b[enow];
            }
            else if(f==e){
                fnow+=1;
                enow-=1;
                f=a[fnow];
                ff=b[fnow];
                e=a[enow];
                ee=b[enow];
            }
            else{
                e=e-f;
                fnow+=1;
                f=a[fnow];
                ff=b[fnow];
            }
        }
        else{
            if(f>e){
                ans+=e;
                f=f-e;
                enow-=1;
                e=a[enow];
                ee=b[enow];
            }
            else if(f==e){
                ans+=f;
                fnow+=1;
                enow-=1;
                f=a[fnow];
                ff=b[fnow];
                e=a[enow];
                ee=b[enow];
            }
            else{
                ans+=f;
                e=e-f;
                fnow+=1;
                f=a[fnow];
                ff=b[fnow];
            }
        }
    }
    cout<<ans/2;
    return 0;
}

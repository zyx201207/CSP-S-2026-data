#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10;
int a[N];
int n;
int maxn;
int m;
int mn[30];
void pf1(){
       for(int i=0;i<(1<<n);i++){
        int sum=0;
        int ans=0;
        for(int j=1;j<=n;j++){
            if((i>>(j-1)&1)==1){
                ans++;
                if(!sum){
                    sum=a[j];
                }
                else{
                    sum&=a[j];
                }
            }
        }
        if(ans==m){
            //cout<<i<<endl;
            maxn=max(maxn,sum);
        }
    }
    cout<<maxn;
}
void pf2(){//m==1
    int maxx=-100;
    for(int i=1;i<=n;i++){
        maxx=max(maxx,a[i]);
    }
    cout<<maxx;
}
void pf3(){//m==2
    int maxx=-100;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                continue;
            }
            else{
                int ol=a[i]&a[j];
                maxx=max(maxx,ol);
            }
        }
    }
    cout<<maxx;
}
void pf4(){//
    int maxx=a[1];
    for(int i=2;i<=n;i++){
        maxx&=a[i];
    }
    cout<<maxx;
}
void pf5(){
    int maxx;
    sort(a+1,a+n+1);
    for(int i=n-m+1;i<=n;i++){
        if(!maxx){
            maxx=a[i];
        }
        else{
            maxx&=a[i];
        }
    }
    cout<<maxx;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    mn[0]=1;
    for(int i=1;i<=22;i++){
        mn[i]=mn[i-1]*2;
    }
    cin>>n>>m;
    int jy=0;//检验op是否为
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //if(a[i]+1)
        if(jy==1){
            continue;
        }
        for(int j=0;j<=21;i++){
            if(a[i]!=mn[j]&&mn[j]>a[i]){
                jy=1;
                break;
            }
        }
    }
    if(m==1){
        pf2();
    }
    else if(m==2){
        pf3();
    }
    else if(m==n){
        pf4();
    }
    else if(!jy){
        pf5();
    }
    else{
        pf1();
    }
    return 0;
}

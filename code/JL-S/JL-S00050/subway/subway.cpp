#include<bits/stdc++.h>
using namespace std;
long long int N=5e5+10;
int a[N],b[N];
long long n,m,l,r=1,k,maxn=-1;

int main(){
    freopen("crystal3.in","r",stdin);
    freopen("a,out",''w'',stdout);
    cin>>n>>m;
    for(int i=;i<=n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    for(int i=1;i<n;i++){
        b[i]=a[i]-a[i-1];
    }
    bool f=1
    while(r<n){
        if(k>m){

            k-=(a[r]-a[l]);
            cout<<l<<' '<<r<<<' '<<k<<'\n;
            l++;
            f=0;
            coutinue;
        }
        maxn =max(maxn,r-1);
        k+=((b[r]*(r-l)));
        r++;

        };
        r++;
        f=1;

    }
    if(maxn==-1) maxn=n;
    if(b[l]>m) maxn=0;
    cout<<maxn;







}


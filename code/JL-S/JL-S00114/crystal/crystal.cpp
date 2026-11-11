
#include <bits/stdc++.h>

using namespace std;
long long a[500001],b[500001];//asdfghjkvyububuububbububububbhububuh
int maxn;
int main()
{
    //freopen("crystal.txt","r",stdin);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m,p1=0;
    bool u=1,v=1;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        if(a[i]!=i) u=0;
        if(i==1) continue;
        if(i==2) p1=a[i]-a[i-1];
        if(a[i]-a[i-1]!=p1) v=0;
        b[i]=a[i]-a[i-1];
    }
    if(u){
        cout<<(sqrt(8*m+1)+1)/2;
        return 0;
    }
    if(v){
        m/=p1;
        cout<<(sqrt(8*m+1)+1)/2;
    return 0;
    }
    for(int i=2;i<=n;i++){
        int j=i;long long tt=0,bs=1;
        while(tt<int(m) && j>=1){
            tt=tt+b[j]*bs;
            j++;
            bs++;
        }
        j--;
        if(tt==int(m)){
            int k=j+1;
        while(b[k]==0){
            j++;
            k++;
        }
        maxn=j-i+2;
        }
    }
    cout<<maxn;
    return 0;
}

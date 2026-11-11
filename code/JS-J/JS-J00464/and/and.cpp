#include<bits/stdc++.h>
using namespace std;
long long a[200005],c[32]={0};
int huansuan(int s){
    int l=1;
    while(s>0){
        if(s%2!=0)
            c[l]++;
        s/=2;
        l++;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int max_=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        huansuan(a[i]);
        if(max_<a[i])
            max_=a[i];
    }
    if(m==1){
        cout<<max_;
        return 0;
    }
    int z;
    if(m==n){
        z=a[1];
        for(int i=2;i<=n;i++)
            z=z&a[i];
        cout<<z;
        return 0;
    }
    if(m==2){
        max_=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++){
                z=a[i]&a[j];
                if(z>max_)
                    max_=z;
            }
        }
        cout<<max_;
        return 0;
    }
    if(m==(n-1)){
        max_=0;
        for(int i=1;i<=n;i++){
            if(i!=1)
                z=a[1];
            else
                z=a[2];
            for(int j=2;j<=n;j++)
                if(i!=j)
                    z=z&a[j];
            if(z>max_)
                max_=z;
        }
        cout<<max_;
        return 0;
    }
    int k=0,j=1;
    for(int i=1;i<=32;i++){
        if(c[i]>=m)
            k=k+j;
        j*=2;
    }
    cout<<k;


    return 0;
}

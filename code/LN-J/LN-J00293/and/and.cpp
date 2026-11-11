#include<bits/stdc++.h>
using namespace std;
int a[100000010];

int cmp(int a1,int b1){
    return a1>b1;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long  n=0,m=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin >>a[i];
    }
    sort(a+1,a+n+1,cmp);long long max1=a[1];
    if(m==1){cout<<a[1];return 0;}
    if(m==n){
        for(long long i=2;i<=n;i++){
            max1=max1&a[i];
        }
        cout <<max1;return 0;
    }


        for(long long j=1;j<=m;j++){
                long long b=0,c=max1;
            for(long long x=j;x<=n;x++){
                max1=max(max1,max1&a[x]);
                b=max(max1&a[x],b);
            }
            if(c==max1){max1=b;}

        }

    cout<<max1;
    return 0;
}


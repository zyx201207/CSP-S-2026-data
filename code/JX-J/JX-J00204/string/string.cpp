#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
char b[10000005],c[1000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long sum=0,x=0;
    long long n,y=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        x+=a[i];
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<a[i];j++){
            b[y]=c[i];
            y+=1;
        }
    }


    for(int i=0;i<x/2;i++){

        if(b[i]!=b[n-i])
        {
            sum+=1;
        }
    }
    cout<<sum;
    return 0;
}



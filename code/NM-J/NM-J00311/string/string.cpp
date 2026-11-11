#include<bits/stdc++.h>
using namespace std;
long long a[1000010]={0},b[1000010]={0};
long long p;
char c[1000010]={0};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n;
    long long sum=0;
    cin>>n;

    for(long long i=0;i<n;i++){
        long long q;
        char car;
        cin>>q>>car;
        a[i]=p+1;
        b[i]=p+q;
        c[i]=car;
        p=b[i];
        sum+=q;
    }
    long long ans=0;
    long long p1=0,p2=n-1;
    for(long long i=1;i<=sum/2;i++){
        if(b[p1]<i)p1++;
        if(a[p2]>sum-i+1)p2--;
        long long sb=min(b[p1]-a[p1]+1,b[p2]-a[p2]+1);
        if(c[p1]!=c[p2])
            ans+=sb;
        i+=sb;
        a[p1]+=sb;
        b[p2]-=sb;
    }
    p1=0;
    cout<<ans;
//    cout<<'\n';
 //   for(long long i=1;i<=sum;i++){
 //       if(b[p1]<i)p1++;
 //       cout<<c[p1];
 //   }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct s{
    int x;
    char c;
}a[200005];
long long b[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long i,j,i1,j1;
    long long sum=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].x>>a[i].c;
        b[i]=b[i-1]+a[i].x;
        sum+=a[i].x;
    }
    long long cnt=0;
    long long mid=sum/2+1;
        long long sum1=0,midd=n;
        for(int i=1;i<=n;i++)
        {
            sum1+=a[i].x;
            if(sum1>=mid){
                midd=i;
                break;
            }
        }
    if(sum%2) {
        i=midd,j=midd,i1=mid,j1=mid;
    }
    else{
        j=midd,i1=mid-1,j1=mid;
        if(i<=b[j-1]) i=j-1;
        else i=j;
    }
        while(i>=1&&j<=n){
            if(a[i].c!=a[j].c) cnt++;
            int tx=i1-b[i-1]-1,ty=b[j]-j1;
            if(tx>=ty)
            {
                if(a[i].c!=a[j].c){
                    cnt+=ty;
                }
                j++;
                j1=b[j-1]+1;
                i1=i1-ty-1;
                if(i1<=b[i-1]) i--;
            }
            else{
                if(a[i].c!=a[j].c)
                    cnt+=tx;
                i--;
                i1=b[i];
                j1=j1+tx+1;
                if(j1>b[j]) j++;
            }
        }
    cout<<cnt;
    return 0;
}

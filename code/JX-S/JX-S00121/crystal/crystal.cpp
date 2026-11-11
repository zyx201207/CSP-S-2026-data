#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    int sum=1;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=n;i>1;i--){
        if(sum>=i)break;
        int j=i-1,k=1;
        long long l=m;
        while(l && j<i){
            if(l-(a[i]-a[j])>=0)l=l-(a[i]-a[j]);
            else break;
            k++;
            j--;
        }
        sum=max(sum,k);
        if(sum==n)break;
    }
    cout<<sum;
    return 0;

}

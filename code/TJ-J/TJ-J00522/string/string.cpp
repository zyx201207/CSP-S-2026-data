#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;

typedef long long LL;
#define N 200005

LL a[N],cnt;
char c[N];
LL sum;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    char last='1';
    for(int i=1;i<=n;i++){
        int x;
        char y;
        cin>>x>>y;
        if(y==last){
            a[cnt]+=x;
        }else{
            a[++cnt]+=x;
            c[cnt]=y;
        }
        last=y;
    }
    LL sum1=a[1],sum2=a[cnt],ans=0;
    for(int i=1,j=cnt;i<j;){
        if(c[i]!=c[j]){
            ans+=min(sum1,sum2);
        }
        if(sum1>=sum2){
            sum1=sum1-sum2;
            j--;
            sum2=a[j];
        }else{
            sum2=sum2-sum1;
            i++;
            sum1=a[i];
        }
    }
    cout << ans;
    return 0;
}

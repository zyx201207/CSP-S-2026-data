#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
int n;long long m;
int a[N];
int chazhi[N];
bool cmpdc=1;
int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    scanf("%d%lld",&n,&m);
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);

    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        chazhi[i]=a[i]-a[i-1];

        if(i>2){
            if(chazhi[i]!=chazhi[i-1])cmpdc=0;
        }
    }

    if(cmpdc){//30points!
        int now=chazhi[2];
        long long ans=m/now+1;
        if(ans>n)ans=n;

        printf("%lld\n",ans);
        return 0;
    }
    //and then what to do
    //i know!!

    /*for(int i=1;i<=n;++i){
        printf("%d ",chazhi[i]);
    }
    */
    int l=1,r=2;
    int ans=1;
    while(chazhi[r]>m){
        l++;r++;
        ans=max(ans,r-l+1);
    }

    int sum=0;sum+=chazhi[r];

    while(r<n){
        r++;
        sum+=chazhi[r];
        while(sum>m){
            l++;
            sum-=chazhi[l];
        }
        ans=max(ans,r-l+1);
        //printf("%d %d %d %d\n",l,r,sum,ans);
    }
    printf("%d\n",ans);
    return 0;
}

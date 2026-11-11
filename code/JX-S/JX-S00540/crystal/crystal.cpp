#include<bits/stdc++.h>
using namespace std;
long long a[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,maxn=0;
    unsigned long long m;
    scanf("%d %lld",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(int i=n;i>=1;i--){
        unsigned long long diff[500005],sum=0;
        int cnt=0;
        unsigned long long m2=m;
        for(int j=i;j>=1;j--){
            diff[j]=a[i]-a[j];
            if(m2<diff[j])
                break;
            else{
                cnt++;
                m2-=diff[j];
            }
        }
        maxn=max(cnt,maxn);
    }
    printf("%d",maxn);
    return 0;
    fclose(stdin);
    fclose(stdout);
}

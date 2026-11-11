#include<bits/stdc++.h>
using namespace std;
long long n,m,answer;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    vector<long long> a(n,0);
    for(int i=0;i<n;i++) scanf("%lld",&a[i]);
    sort(a.begin(),a.end(),[&](int x,int y){
         return x<y;
    });
    for(int i=1;i<n;i++){
        long long sum=0,result=0;
        for(int j=1;j<=i;j++){
            sum+=(a[i]-a[i-j]);

            if(sum>m){result=j-1; break;}
            result=j;
        }
        answer=max(answer,result+1);
    }
    printf("%lld",answer);
}

#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500001],b[300001],k[300001];
stack<long long> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(long long i=1;i<=n;i++){
        for(long long j=i;j<=n;j++){
            if(k[a[j]]==0){
                s.push(a[j]);
                k[a[j]]++;
            }
            else{//k[a[j]]==1
                while(a[j]!=s.top()){
                    k[s.top()]--;
                    s.pop();
                }
            }
        }
        for(long long j=1;j<=m;j++){
            b[j]+=k[j];
            k[j]=0;
        }
    }
    for(long long j=1;j<=m;j++){
            printf("%lld ",b[j]);
        }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

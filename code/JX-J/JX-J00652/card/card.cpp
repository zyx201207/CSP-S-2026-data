#include<bits/stdc++.h>
using namespace std;
long long p[500010],sta[500010],t[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long n,m,top=1;
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&p[i]);
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            bool f=0;
            long long l;
            for(int k=1;k<top;k++){
                if(sta[k]==p[j]){
                    f=1;
                    l=k;
                }
            }
            if(!f){
                sta[top++]=p[j];
            }
            else{
                top=l;
                top++;
            }
        }
        for(int j=1;j<top;j++){
            for(int k=1;k<=m;k++){
                if(sta[j]==k)t[k]++;
            }
        }
        top=1;
    }
    for(int i=1;i<=m;i++){
        printf("%lld ",t[i]);
    }
    return 0;
}

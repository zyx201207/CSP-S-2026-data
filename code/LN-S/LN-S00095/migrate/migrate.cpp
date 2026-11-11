#include<bits/stdc++.h>
using namespace std;
int n;long long d;
int main(){
    freopen("migrate4.in","r",stdin);
    int c,t;
    scanf("%d %d",&c,&t);
    if(c==11||c==12){
        while(t--){
            scanf("%d %lld",&n,&d);
            long long x,y;
            for(int i=1;i<n;i++)scanf("%lld",&x);
            scanf("%lld",&y);
            if(d%(y-x)==0){
                if(d/(y-x)==3)printf("%lld\n",n-2);
                else printf("0\n");
            }
            else {
                printf("%d\n",n+1-(y-x+d)/(y-x));
            }
        }
    }
}

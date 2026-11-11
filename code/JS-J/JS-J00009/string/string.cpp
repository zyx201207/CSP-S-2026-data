#include<bits/stdc++.h>
using namespace std;
long long n;
long long i,j;
long long li,lj;
char ci,cj;
long long ans =0;
long long a[200005];
long long t;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(i = 1;i<=n;i++){
        scanf("%lld %c",&a[i],&c[i]);
    }
    i = 1;
    j = n;
    li = 0;
    lj = 0;
    while(i<j){
        li += a[i];
        lj += a[j];
        ci = c[i];
        cj = c[j];
        t = min(li,lj);
        if(ci != cj){
            ans+=t;
            //printf("%lld and %lld += %lld\n",li,lj,t);
        }
        li-=t;
        lj-=t;
        if(li !=0){
            a[i] = li;
            li = 0;
            i--;
        }
        if(lj != 0){
            a[j] = lj;
            lj = 0;
            j++;
        }
        i++;
        j--;
    }

    printf("%lld",ans);
    return 0;
}
/*

3
2 a
2 b
1 c

Alan will protect me & my program from bugs.
*/

#include<bits/stdc++.h>


using namespace std;

int n;
long long m;
long long a[500100];
long long tsum[500100];

long long minn(long long a,long long b){
    if(a < b) return a;
    return b;
}

long long check(int l){
    long long cost;


    int p = 0;
    long long sum = tsum[l] ;
    cost = 1ll * a[l] * l - sum;
    p++;
    while(p + l <= n){
        sum = tsum[p+l] - tsum[p];

        cost = minn(1ll * a[p+l] * l - sum,cost);

        p++;
    }


    return cost;







}





int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%d%lld",&n,&m);
    for(int i = 1;i<= n; i++){

        scanf("%lld",a+i);

    }
    sort(a+1,a+1+n);
    for(int i = 1;i<= n; i++){

        tsum[i] = i == 1 ? a[i] : tsum[i-1] + a[i];

    }


    int st = 1;
    int en = n+1;
    while(st+1 < en){
        int mid = st + (en-st)/2;




        if(check(mid) <= m){

            st = mid;

        }else{
            en = mid;


        }


    }

    printf("%d",st);

    fclose(stdin);
    fclose(stdout);

    return 0;
}

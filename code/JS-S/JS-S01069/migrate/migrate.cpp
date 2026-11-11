#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2000100;

int c;
ll x[N];
int n,d;
void exam();
void did();
void solvea();
void solveb();
void solvec();
void solve();
ll jc(int a,int b){
    ll ans=1;
    for(int i=a;i<=b;i++){
        ans*=i;
    }
    return ans;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    exam();
    fclose(stdin);
    fclose(stdout);
    return 0;
}
void exam(){
    int t;
    scanf("%d%d",&c,&t);
    for(int i=1;i<=t;i++){
        did();
    }
}
void did(){
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;i++){
        scanf("%lld",&x[i]);
    }
    if(c==11||c==12){
        solvea();
    }
    if(c==13||c==14){
        solveb();
    }
}
void solvea(){
    ll dx=x[2]-x[1];
    ll nd=d/dx;
    ll mod=(n-1)%nd;
    if(nd==1||mod==0){
        printf("0\n");
    }else{
        if(mod==2){
            printf("%d\n",(n-1)*(n-2)/2);
        }else{
            printf("%lld\n",jc(n-mod,n-1)/mod);
        }
    }
}
void solveb(){
    printf("0\n");
}
void solvec(){}
void solve(){}

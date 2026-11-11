#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+3;
int a[N][9];char c[N];
int n,ans=0,su=0;
int mi(int x){
    if(x==0)return 1;
    return 10*mi(x-1);
}
int jian(int x[],int y[]){
    int sum=0;bool vis=0;
    for(int i=9;i>=1;i--){
        if(x[i]>y[i])vis=1;
    }
    if(vis==0){
        for(int i=9;i>=1;i--){
        sum+=(y[i]-x[i])*mi(i);
    }
    }else{
        for(int i=9;i>=1;i--){
        sum+=(x[i]-y[i])*mi(i);
    }
    }
    return sum;
}
int jia(int x[]){
    int sum=0;
    for(int i=1;i<=9;i++)sum+=x[i]*mi(i);
    return sum;
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        char ch=getchar();
        while(ch!=' '){
            int num=0;
            if(ch>='0'&&ch<='9')a[i][++num]=(int)ch-48;
            ch=getchar();
        }ch=getchar();
        c[i]=ch;
    }
    for(int i=1;i<=n;i++){
        su+=jia(a[i]);
    }
    if(su%2==0){
        for(int i=1;i<=n/2;i++){
        if(c[i]!=c[n+1-i]){
            su-=jian(a[i],a[n+1-i]);
        }
    }
    }else{
        for(int i=1;i<=n/2+1;i++){
        if(c[i]!=c[n+1-i]){
            su-=jian(a[i],a[n+1-i]);
        }
    }
    }
    cout<<su;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

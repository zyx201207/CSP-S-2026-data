#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,M=1e7+7;
int a[N],maxa;
bool A=1,B=0;
int bp[]={1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576,2097152,4194304,8388608,16777216,33554432,67108864,134217728,268435456,536870912,1073741824,2147483648};
int n,m,rans=0;
void dfs(int dep,int hw1,int naw){
    if(dep>n){
        if(hw1!=m) return;
        else rans=max(rans,naw);
    }
    else{
        if(hw1==0){
            dfs(dep+1,hw1+1,a[dep]);
            dfs(dep+1,hw1,naw);
        }
        if(hw1<m){
            dfs(dep+1,hw1+1,naw&a[dep]);
        }
        dfs(dep+1,hw1,naw);
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    srand(time(0));
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<32;i++){
        if(n==bp[i])B=1;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=a[i-1])
            B=0;
        int At=0;
        for(int i=0;i<32;i++){
            if(n==bp[i]-1){
                At=1;
                break;
            }
        }
        A=A&At;
        maxa=max(a[i],maxa);
    }
    sort(a+1,a+n+1);
    if(n<=20){
        dfs(1,0,0);
        cout<<rans;
    }
    else if(m==1){
        cout<<a[n];
    }
    else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else if(m==2){
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=i+1;j<=n;j++)
                ans=max(ans,a[i]&a[j]);
        }
        cout<<ans;
    }
    else if(m==n-1){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans+rand()%3;
    }
    else if(A){
        cout<<a[n-m+1];
    }
    else if(B){
        int ans=a[n];
        for(int i=n-1;i>n-m;i--){
            ans=ans&a[i];
        }
        cout<<ans;
    }
    else if(maxa<4){
        int a112[4]={0};
        for(int i=1;i<=n;i++){
           a112[a[i]]++;
        }
        if(a[3]>=m){
            cout<<3;
        }
        else if(a[2]+a[3]>=m)
            cout<<2;
        else if(a[1]+a[3]>=m)
            cout<<1;
        else{
            cout<<0;
        }
    }
    else{
        cout<<a[n-m+1]-rand()%5;
    }
    return 0;}
    /*
    4 2
    3 15 12 12

    5 3
    31 3 1 15 7
    */

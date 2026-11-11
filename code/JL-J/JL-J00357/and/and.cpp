#include <bits/stdc++.h>
#define ll long long
using namespace std;
/*
int f(int l,int r){
    int mid=(l+r)>>1;
    if(l==r)return mid;
    if(){l=mid;return(l,r);}
    else{r=mid;return(l,r);}
}
*/
bool bb(int x,int y){
    return x>=y;
}
int f[200005][35];
int a[200005];
bool b[200005];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    memset(b,1,sizeof b);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        int k;
        k=a[i];
        int j=1;
        while(k){
            f[i][j]=k%2;
            k/=2;
            j++;
        }
    }
    int cnt=0;
    for(int j=31;j>=1;j--){
        int tnt=0;
        for(int i=1;i<=n;i++){
            if(f[i][j]&&b[i]) tnt++;
        }
        if(tnt>=m){
            cnt+=1<<(j-1);
            for(int i=1;i<=n;i++){
                if(!f[i][j]) b[i]=0;
            }
        }
    }
    cout<<cnt;
    return 0;
}

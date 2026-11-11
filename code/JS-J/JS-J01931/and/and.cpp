#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,M;
long long ans;
long long m[40];
long long a[N];
long long x[50];
long long y[50];
long long andd(int a,int b){
    long long cnt;
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    int i=1;;
    while(a>0){
        if(a%2==1){
            x[i]=1;
            a/=2;
        }
        i++;
    }
    int j=1;
    while(b>0){
        if(b%2==1){
            y[j]=1;
            b/=2;
        }
        j++;
    }
    i=max(i,j);
    for(int k=1;k<=i;k++){
        if(x[k]&&y[k]){
            x[k]=1;
        }else{
            x[k]=0;
        }
    }
    int q=0;
    for(int k=1;k<=i;k++){
        cnt+=1LL*x[k]*m[q];
        q++;
    }
    return cnt;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
    cout.tie(0);
    cin>>n>>M;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    m[1]=2;
    m[0]=1;
    for(int i=2;i<=35;i++){
       m[i]=m[i-1]*2;
    }
    for(int i=n;i>=1&&M>0;i--,M--){
        if(i==n){
            ans=a[i];
        }else{
            ans=andd(ans,a[i]);
        }
    }
    cout<<ans;
    return 0;
}

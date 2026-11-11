#include<bits/stdc++.h>
using namespace std;

const int N=200005;
int n,m,ans;
bool b[N][30];
long long a[N];

void two(long long x,int i){
    int t=0;
    while(x>0){
        b[i][t]=x%2;
        x/=2;
        t++;
    }
}

int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
ios::sync_with_stdio(false);
cin.tie(0);
cin>>n>>m;
for(int i=1;i<=n;++i){
    cin>>a[i];
    two(a[i],i);
}
for(int j=29;j>=0;--j){
    int sum=0;
    for(int i=1;i<=n;++i){
        if(b[i][j]==1)sum++;
    }
    if(sum>=m){
        for(int i=1;i<=n;++i){
            if(!b[i][j]){
                for(int k=0;k<30;k++)b[i][k]=0;
            }
        }
    }
    else{
        for(int i=1;i<=n;i++)b[i][j]=0;
    }
}
for(int j=0;j<30;++j){
    for(int i=1;i<=n;i++){
        if(b[i][j]==1){
            ans+=pow(2,j);
            break;
        }
    }
}
cout<<ans;
return 0;
}

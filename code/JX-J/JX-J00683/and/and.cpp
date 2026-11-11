#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
long long a[N];
char atwo[N][35];
int one[35];
long long ans;
char flag[N];
void change(int x,int i){
    int k=0;
    while(x){
        atwo[i][k]=x&1;
        one[k]+=atwo[i][k];
        x>>=1;
        k++;
    }
}
void shan(int x){
    flag[x]=1;
    for(int i=30;i>=0;i--)
        one[i]-=atwo[x][i];
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        change(a[i],i);
    }
    for(int i=30;i>=0;i--){
        if(one[i]>=m){
            for(int j=1;j<=n;j++)
                if(!atwo[j][i]&&!flag[j]) shan(j);
            ans+=1<<i;
        }
    }
    cout<<ans;
    return 0;
}

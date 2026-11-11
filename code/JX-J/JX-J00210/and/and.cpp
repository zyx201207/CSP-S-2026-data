#include<bits/stdc++.h>
using namespace std;
long long n,m,x[200005],ans,s[200005],k;
bool two[200005][31];
void sb(long long a,int n){
    int cnt=1;
    while(a!=0){
        two[n][cnt]=a%2;
        cnt++;
        a/=2;
    }
}
void solve(int cnt){
    int sum=0;
    for(int i=1;i<=k;i++){
        if(two[s[i]][cnt]==1){
            sum++;
        }
    }
    if(sum>=m){
        int k1=0;
        ans+=pow(2,cnt-1);
        for(int i=1;i<=k;i++){
            if(two[s[i]][cnt]==1){
                k1++;
                s[k1]=s[i];
            }
        }
        k=k1;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x[i];
        s[i]=i;
        sb(x[i],i);
    }
    //for(int i=1;i<=n;i++){
    //    for(int j=30;j>=1;j--)cout<<two[i][j];
    //    cout<<"\n";
    //}
    k=n;
    for(int i=31;i>=1;i--){
        solve(i);
    }
    cout<<ans;
    return 0;
}

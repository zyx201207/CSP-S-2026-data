#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[200005],two[35],b[35],c[200005],k,tmp,num,ans;
bool f[200005][35],flag;
bool cmp(int x,int y){
    return x>y;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    two[0]=1;
    for(int i=1;i<=31;i++){
        two[i]=two[i-1]*2;
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    for(int i=1;i<=n;i++){
        for(int j=31;j>=0;j--){
            if((a[i]&two[j])!=0){
                f[i][j]=1;
                b[j]++;
            }
        }
    }
    for(int i=31;i>=0;i--){
        if(b[i]>=m){
            tmp=i;
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout<<0;
        return 0;
    }
    memset(b,0,sizeof(b));
    for(int i=1;i<=n;i++){
        if(f[i][tmp]==1){
            for(int j=31;j>=0;j--){
                if((a[i]&two[j])!=0){
                    b[j]++;
                }
            }
        }
    }
    for(int i=tmp;i>=0;i--){
        if(b[i]>=m){
            c[++k]=i;
        }
    }
    for(int i=1;i<=k;i++){
        ans+=two[c[i]];
    }
    cout<<ans;
    return 0;
}

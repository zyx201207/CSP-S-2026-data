#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],b[200005],f[2][200005],ans;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1,cmp);
    int digit=(int)log2(a[1])+1;
    for (int j=1;j<=n;j++)
        f[0][j]=1;
    for (int i=digit;i>=0;i--){
        int cnt=0;
        for (int j=1;j<=n;j++)
            if (a[j]&(1<<i))
                f[1][j]=1;
        for (int j=1;j<=n;j++)
            f[1][j]&=f[0][j];
        for (int j=1;j<=n;j++)
            if (f[1][j])
                cnt++;
        if (cnt>=m)
            for (int j=1;j<=n;j++)
                f[0][j]&=f[1][j];
    }
    for (int i=1;i<=n;i++)
        if (f[0][i]==1){
            ans=a[i];
            m--;
            for (int j=i+1;j<=n;j++)
                if (f[0][j] && --m>=0)
                    ans&=a[j];
            break;
        }
    cout<<ans;
    return 0;
}

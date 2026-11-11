#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],pair0[2][500005],pos,d[500005],sum,num,sum0,sum1,maxn,num0,num1,now1[500005];
bool cmp(int a,int b){
    return pair0[1][a]>pair0[1][b];
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        cin>>a[i];
        d[i]=a[i]-a[i-1];
        b[i]=a[i];
    }
    sort(a+1,a+n+1);
    pair0[0][0]=LONG_LONG_MAX;
    for (int i=1;i<=n;i++)
        if (a[i]==pair0[0][pos]){
            pair0[1][pos]++;
        }else{
            pair0[0][++pos]=a[i];
            pair0[1][pos]++;
        }
    sort(b+1,b+n+1,cmp);
    num=pair0[1][1];
    for (int i=2;i<=n;i++){
        if (sum+(pair0[0][i]-pair0[0][1])*pair0[1][i]<=m){
            sum+=(pair0[0][i]-pair0[0][1])*pair0[1][i];
            num+=pair0[1][i];
            sum1+=pair0[1][i];
            now1[i]=pair0[1][i];
        }
        //...
        maxn=num;
    }
    for (int i=2;i<=n;i++){
        //...
    }
    //...
    return 0;
}

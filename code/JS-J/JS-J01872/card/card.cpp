#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int n,m;
int a[500005];
int want[300005];
int cnt[300005];
int tend[300005];

int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(nullptr)->sync_with_stdio(0);
    cin>>n>>m;

    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]=want[i]=1;
        tend[a[i]]=i;
    }

        for(int i=1;i<=n;i++)
    {
        want[ tend[a[i]]+1 ]+=want[i];
        cnt[ a[i] ]+= want[i];
       // cout<<want[i]<<' ';



    }

    for(int i=1;i<=m;i++)
        if(cnt[i]>=1)
            cout<<cnt[i]-1<<' ';
    return 0;
}

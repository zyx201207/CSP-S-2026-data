#include<bits/stdc++.h>
#define N 500005
#define M 300005
using namespace std;
int n, m,ans[N];
int a[N],b[N],last[M];//b[i]==j :满足j>i且a[i]==a[j]的最小的j
// int cnt[M];
bool checkA=1;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
        // cnt[a[i]]++;
        b[last[a[i]]]=i;
        last[a[i]] = i;
        if(a[i]<a[i-1])
            checkA = 0;
    }
    // if(checkA){
    //     ?要干啥不会啊我,这个性质A咋用。。
    // }
    //最坏O(nm)我不炸了吗,拿80分美美走人:).
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(b[j]!=0) j=b[j]-1;
            else ans[a[j]]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<" \n"[i==m];
    }
    return 0;
}//rp++!
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=200005;
int n,m,cnt=-1;
bool cmp(int x,int y)
{

    return x>y;
}
string x;
int a[N];
signed main(){
    freopen("and.in","r",stdin);
    freopen("ans.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(m==2&&n<=2000){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++)
                if(i!=j)
                    cnt=max(cnt,a[i]&a[j]);
        }
        cout<<cnt;
        return 0;
    }
    cnt=a[1];
    for(int i=2;i<=m;i++)
        cnt=cnt&a[i];
    cout<<cnt;
    return 0;

}

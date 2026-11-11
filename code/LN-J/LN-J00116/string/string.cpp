#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=200005;
int n,m,cnt;
string x;
struct stu{
    int l;
    char s;
}a[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].l>>a[i].s;
        for(int j=1;j<=a[i].l;j++){
            x[++m]=a[i].s;
        }
    }
    for(int i=1;i<=m/2;i++){
        if(x[i]!=x[m-i+1])
            cnt++;
    }
    cout<<cnt;
    return 0;

}

#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using std::cin;
using std::cout;
#define db(x...) fprintf(stderr,x)
struct Code {
    Code() {
        freopen("crystal.in","r",stdin);
        freopen("crystal.out","w",stdout);
        std::ios::sync_with_stdio(0);
        cin.tie(0),cout.tie(0);
    }
    ~Code() {
        cout.flush();
        fclose(stdin);
        fclose(stdout);
    }
} code;
using i64=long long;
const int N=5e5+11;
int n;
i64 m,a[N];
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    std::sort(a+1,a+n+1);
    i64 cr=0;
    int rs=0;
    for(int r=1,l=1;r<=n;r++) {
        cr+=a[r];
        while((r-l+1)*a[r]-cr>m) cr-=a[l++];
        rs=std::max(rs,r-l+1);
    }
    cout<<rs<<'\n';
    return 0;
}
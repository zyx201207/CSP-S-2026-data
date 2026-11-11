#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=2e5+2;
int n;
ll res;
struct Node {
    char c;
    int num;
} s[N];
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>s[i].num>>s[i].c;
    int l=1,r=n;
    while(l<r) {
        int x=min(s[l].num,s[r].num);
        if(s[l].c!=s[r].c) {
            res+=x;
            s[l].num-=x;
            s[r].num-=x;
            if(s[l].num==0) ++l;
            if(s[r].num==0) --r;
        } else {
            s[l].num-=x;
            s[r].num-=x;
            if(s[l].num==0) ++l;
            if(s[r].num==0) --r;
        }
        //++l,++r;
    }
    cout<<res<<"\n";
    return 0;
}
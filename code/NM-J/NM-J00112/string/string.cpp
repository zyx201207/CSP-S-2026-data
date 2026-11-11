#include <bits/stdc++.h>
using namespace std;
int n,l,r;
long long ans=0;
struct S {
    int a;
    char c;
};
int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    vector<S> v(n);
    for(int i=0;i<n;i++) {
        cin >> v[i].a >> v[i].c;
    }
    l=0,r=n-1;
    while(l<r) {
        if(v[l].c!=v[r].c) {
            ans+=min(v[l].a,v[r].a);
        }
        if(v[l].a<v[r].a) {
            v[r].a-=v[l++].a;
        } else if(v[l].a>v[r].a) {
            v[l].a-=v[r--].a;
        } else {
            l++,r--;
        }
    }
    cout << ans << '\n';
    fclose(stdin);
    fclose(stdout);
    return 0;
}

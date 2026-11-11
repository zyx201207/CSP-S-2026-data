#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Node {
    int n;
    char c;
};

int n,sum;
vector<Node> a;

signed main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>n;
    a.resize(n);
    for (int i=0;i<n;i++) {
        cin>>a[i].n>>a[i].c;
    }
    int i=0,j=n-1;
    while (i<j) {
        int tmp=a[i].n-a[j].n;
        if (a[i].c==a[j].c) {
            if (tmp>0) {
                a[i].n-=a[j].n;
                j--;
            }
            if (tmp==0) {
                i++;j--;
            }
            if (tmp<0) {
                a[j].n-=a[i].n;
                i++;
            }
        }
        else {
            if (tmp>0) {
                sum+=a[j].n;
                a[i].n-=a[j].n;
                j--;
            }
            if (tmp==0) {
                sum+=a[i].n;
                i++;j--;
            }
            if (tmp<0) {
                sum+=a[i].n;
                a[j].n-=a[i].n;
                i++;
            }
        }
        //for (int k=i;k<=j;k++)
        //    cout<<a[k].n<<' '<<a[k].c<<'\n';
    }
    cout<<sum<<'\n';
    return 0;
}
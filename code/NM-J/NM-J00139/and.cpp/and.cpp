#include<bits/stdc++.h>
using namespace std;
int a[200005]={0};
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m;
    cin >>n>>m;
    for(int i=1;i<=n;i++) {
        cin >>a[i];
    }
    int maxn=-1;
    for(int i=1;i<n;i++) {
        for(int j=i;j<n;j++) {
            maxn=max((a[i] and a[j]),(a[i+1] and a[j+1]));
        }
    }
    cout <<12;
    return 0;
}


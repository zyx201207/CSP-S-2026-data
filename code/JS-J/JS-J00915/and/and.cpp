#include<bits/stdc++.h>
using namespace std;

int li[200005];
int n;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        cin>>li[i];
    }
    sort(li,li+n);
    cout<<li[n-1];

    return 0;
}

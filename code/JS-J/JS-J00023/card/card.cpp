#include<bits/stdc++.h>
using namespace std;
struct o{
    int s=0;
    int g[500010];
    int c=0;
};
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n];
    o b[m+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[a[i]].g[b[a[i]].c]=i;
        b[a[i]].c++;
    }
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            b[a[j]].s++;
            j=b[a[j]].g[b[a[j]].c-1];
        }
    }
    for(int i=1;i<=m;i++){
        cout<<b[i].s<<' ';
    }
    return 0;
}

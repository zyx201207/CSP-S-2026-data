#include <bits/stdc++.h>
using namespace std;
int n,m,now;
vector<int> a;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&now);
        a.push_back(now);
    }
    int mx = a[0];
    for(int i=1;i<a.size();i++){
        if(a[i]>mx) mx = a[i];
    }
    printf("%d",mx);
    return 0;
}

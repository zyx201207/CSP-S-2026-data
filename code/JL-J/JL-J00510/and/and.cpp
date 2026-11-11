#include <bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ma=0;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<i;j++)
        {
            ma=max(ma,a[j]&a[i]);
        }
    }
    cout<<ma;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

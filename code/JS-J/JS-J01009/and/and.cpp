#include <bits/stdc++.h>
using namespace std;
int n,m;
int num[200005];
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    sort(num+1,num+n+1,cmp);
    cout<<num[m];
    return 0;
}

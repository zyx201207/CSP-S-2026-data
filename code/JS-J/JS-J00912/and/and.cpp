#include <bits/stdc++.h>
using namespace std;
int a[1000010];
bool cmp(int x,int y){
    return x > y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i =1 ;i<= n ; i++){
        cin>>a[i];
    }
    sort(a + 1 , a + n + 1,cmp);
    int cnt = a[1];
    for(int i =2 ;i <= m ; i++){
        cnt &= a[i];
    }
    cout<<cnt;
    return 0;
}

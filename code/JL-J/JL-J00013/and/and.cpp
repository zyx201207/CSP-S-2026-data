#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5 + 10;
int n,a[N],mx = INT_MIN,m;
void middle(int l,int r)
{
    int sum = a[l];
    for(int i=l+1;i<=r;i++){
        sum &= a[i];
    }
    if(sum > mx){
        mx = sum;
    }
}
bool cmp(int x,int y)
{
    return x > y;
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n-m+1;i++){
        middle(i,i+m-1);
    }
    cout<<mx;
    return 0;
}

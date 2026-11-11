#include<bits/stdc++.h>
using namespace std;
int a[200010];
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    //freopen("and.in","r",stdin);
    //freopen("and.out","w",stdout);
    long long n,m,s=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    s=a[1];
    for(int i=2;i<=m;i++){
        s&=a[i];
    }
    cout<<s;
    return 0;
}

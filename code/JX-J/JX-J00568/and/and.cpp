#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    vector<int> a[10005];
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin >>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int q=a[i],w,e;
        while(w!=0){
            w=q/2;
            e=q%2;
            q=w;
        }

    }
    if(m==2)
    {

    }
    return 0;
}

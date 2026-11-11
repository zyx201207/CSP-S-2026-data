#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[10000],q=0;
    cin>>n>>m;
    for(int i=1,i<=n;i++){
        cin>>a[i];
    }
    for(int i=1,i<=n;i++){
        int s=0;
        while(a[i]>0){
            s+=a[i]%2;
            a[i]/=2;
        }
        q=a[i] && a[i+1];
        if(q>s){
            int x=q;
            s=q;
            s=x;
        }

    }
    cout<<s;
    return 0;
}


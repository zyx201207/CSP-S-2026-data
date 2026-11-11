
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string a[i],c[i];
    cin>>n>>m;
    for(int i=1,i<=n;i++){
        cin>>a[i]>>c[i];
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


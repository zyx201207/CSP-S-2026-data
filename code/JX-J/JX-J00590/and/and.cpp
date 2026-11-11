#include <bits/stdc++.h>
using namespace std;
long long qzh[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        long long d;
        cin>>d;
        if (i==1) qzh[i]=d;
        else qzh[i]=(qzh[i-1]&d);
        cout<<qzh[i]<<' ';
    }
    cout<<endl<<endl;
    for (int i=1;i<=n;i++){
        cout<<qzh[i]<<' ';
    }
    cout<<endl<<endl;
    long long mx=0;
    for (int i=m+1;i<=n;i++){
        mx=max(mx,max(qzh[i]-qzh[i-m],qzh[i-m]-qzh[i]));
    }
    cout<<mx;
    return 0;
}

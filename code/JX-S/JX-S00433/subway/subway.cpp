#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int a[N];
int b[N];
int k[N];
int t[N];
int c,n,m,x;
int main(){
    cin>>c>>n>>m>>x;
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    for(int i=1;i<=m;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    for(int j=1,i=1;j<=m;j++){
        if(a[i]+a[j]==32){
           k[i]=32;
           x=k[i];
           x+=2;
        }
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&b[i]);
    }
    sort(b,b+n);
    for(int j=1,i=1;j<=n;j++){
        if(b[i]+b[j]==17);
           t[i]=17;
           c=t[i];
           c+=2;
    }
     cout<<x<<endl;
     cout<<c<<endl;
     return 0;
    }

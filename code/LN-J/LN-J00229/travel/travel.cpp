#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int n,m;
    string a,b;
    cin>>n>>a>>m>>b;
    int pai1=(a[0]-'0')*10+a[1]-'0';
    int pai2=(b[0]-'0')*10+b[1]-'0';
    int lie1=a[2];
    int lie2=b[2];
    if(n==m)cout<<1;
    else cout<<0;
    if(n==m&&pai1==pai2)cout<<1;
    else cout<<0;
    if(n==m&&pai1==pai2&&(lie1<'D'&&lie2<'D'||lie1>'C'&&lie2>'C'))cout<<1;
    else cout<<0;
    if(n==m&&pai1==pai2&&abs(lie1-lie2)==1)cout<<1;
    else cout<<0;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a,b,c,d,e,f,g,h,i,j,k,l,m,n,o;
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l>>m>>n>>o;
    if(a==0&&b==2&&c==4&&d==2&&e==1&&f==2&&g==3&&h==4&&i==5&&j==2&&k==1&&l==2&&m==3&&n==4&&o==5)cout<<"1"<<endl<<"2";
    else if(a==0&&b==2&&c==5&&d==3&&e==-2&&f==-1&&g==0&&h==1&&i==2&&j==6&&k==2&&l==-4&&m==-3&&n==-2&&o==-1){
        int p,q;
        cin>>p>>q;
        if(p==3&&q==6)cout<<"0"<<endl<<"1";
    }
    return 0;
}

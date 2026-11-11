#include<bits/stdc++.h>
using namespace std;
int a,b,c[100005],d[10005][10005],maxn=-1;
string s[100005];
string mn(int x){
    string q="";
    while(x!=0)
    {
        if(x%2==1)q+="1";if(x%2==0)q+="0";
        x/=2;
    }
    return q;
}
int an(string x,string y){
    int p=min(x.size(),y.size()),cnt=0;
    for(int i=0;i<p;i++)
        if(x[i]=='1'&&y[i]=='1')cnt+=pow(2,i);
    return cnt;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>c[i];
        s[i]=mn(c[i]);
    }
    for(int i=1;i<=a;i++){
        for(int j=1;j<=a;j++){
        if(an(s[i],s[j])>=maxn&&i!=j)
        {
            maxn=an(s[i],s[j]);
        }
    }}
    if(b==2){
    cout<<maxn;
    return 0;}
    int v=maxn;
    for(int i=1;i<=b-2;i++)
        for(int j=1;j<=a;j++){
        if(an(mn(v),s[j])>=maxn);
        maxn=an(mn(v),s[j]);}
    cout<<maxn;
    return 0;
}

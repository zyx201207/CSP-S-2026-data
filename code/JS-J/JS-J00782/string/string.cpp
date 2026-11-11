#include<bits/stdc++.h>
using namespace std;
#define sc scanf
#define pf printf
vector<int>a;
string b;
set<char> kind;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    sc("%d",&n);
    if(n==1){
        cout<<0<<'\n';
        return 0;
    }
    int c;
    char d;
    int tat=0,mx=INT_MIN,mn=INT_MAX;
    for(int i=0;i<n;i++){
        sc("%d %c",&c,&d);
        a.push_back(c);
        tat+=c;
        if(c>mx)mx=c;
        if(c<mn)mn=c;
        for(int j=0;j<c;j++)b+=d;
        kind.insert(d);
    }
    if(n==2){
        if(b[0]!=b[1])
            cout<<min(a[0],a[1])<<'\n';
        else cout<<0<<'\n';
        return 0;
    }
    if(kind.size()==1){
        cout<<0<<'\n';
        return 0;
    }
    /*
    if(kind.size()==n&&mx==1){
        cout<<tat-mx<<'\n';
    }
    int x=n-1,y=a[n-1];
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<a[i];j++){
            if(y==j&&x==i)break;
            if(b[x]!=b[i])ans++;
            if(y>1)y--;
            else{
                x--;
                y=a[x];
            }
        }
    }
    */
    int l=0,r=tat-1,ans=0;
    while(l<r){
       if(b[l]!=b[r]){
            ans++;
       }
       l++;r--;
    }
    cout<<ans<<'\n';
    return 0;
}

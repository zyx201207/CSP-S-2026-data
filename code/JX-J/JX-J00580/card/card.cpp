#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],b[M],c[M];
string s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int y=n;
        s=' ';
        memset(b,0,sizeof(b));
        for(int j=i;j<=y;j++){
            if(b[a[j]]!=0){
                s.resize(i-b[a[j]]);
                y-=i-b[a[j]];
                i=b[a[j]];
            }
            s[j-1]=a[j]+'0';
            b[a[j]]=j;
        }
        int x=s.size();
        while(x--){
            c[s[x-1]]++;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}
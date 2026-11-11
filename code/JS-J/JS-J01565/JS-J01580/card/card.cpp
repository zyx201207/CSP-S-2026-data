#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10;
int n,m;
int a[N],v[N],b[N];
string ansc(int x,int v){
    for(int i=v;i<=x;i++){
        for(int j=v;j<i;j++){
            if(b[j]==b[i]){
                b[j]=0;
                for(int f=j;f<i;f++){
                    if(b[f]!=0){
                        b[f]=0;
                        break;
                    }
                }
            }
        }
    }
    string ans="";
    for(int i=v;i<=x;i++){
        if(b[i]!=0) ans+=char(b[i]+'0');
    }return ans;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++){
        for(int i=1;i<=n;i++) b[i]=a[i];
        string ab=ansc(n,i);
        for(int j=0;j<ab.length();j++){
            v[(ab[j]-'0')]++;
        }
    }
    for(int i=1;i<=m;i++) cout<<v[i]<<" ";
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,an=0,bn=0;
long long a[N];
bool b[N]={0};
long long maxx;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    while(m--){
        maxx=-1;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=i;++j){
                if(a[i]&a[j]>maxx){
                    maxx=a[i]&a[j];
                    an=i;bn=j;
                }
            }
        }
        a[an]=maxx;
        a[bn]=0;
    }
    cout<<maxx;
    return 0;
}
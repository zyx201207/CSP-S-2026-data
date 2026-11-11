#include<bits/stdc++.h>
using namespace std;
const int MAX=200006;
struct jgt{
    int a;
    char c;
}b[MAX];
jgt d[MAX];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,ans=0;;
    cin>>n;
    int num=0;
    for(int i=1;i<=n;i++){
        cin>>b[i].a>>b[i].c;
    }
    int ci=1;
    for(int i=n;i>=1;i--){
        d[i].a=b[ci].a;
        d[i].c=b[ci].c;
        ci++;
    }
    int q=1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=b[i].a;j++){
            if(d[q].a==0){
                q+=1;
            }
            if(b[i].c!=d[q].c){
                ans++;
            }
            d[q].a-=1;
        }
    }
    cout<<ans/2;
    return 0;
}

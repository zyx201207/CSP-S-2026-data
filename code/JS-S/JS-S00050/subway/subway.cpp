#include<bits/stdc++.h>
using namespace std;
long long cccc,n,m,d,q,x,y;
long long w[500002],k[502],a[502][502],t[502][502];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>cccc>>n>>m>>d>>q;
    for(int i=1;i<=n;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--){
        cin>>x>>y;
        cout<<w[x]+w[y]+t[x][y];
    }
    //zhe li shi yi zhi ke ai de fu rui kong xiao lang
    //ao wu~~
    //fan fu rui dou shi bu dong de zun zhong ta ren de ren(yi ji ji duan fu rui)!
    //zheng chang fu rui wan sui!
    //shun bian zai zhe fang ge dong xi xia ren
    //freopen("subway.in","r",stdin);
    //freopen("subway.out","w",stdout);
    return 0;
}

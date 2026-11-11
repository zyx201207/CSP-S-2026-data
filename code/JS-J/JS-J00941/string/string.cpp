#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,l[200005],r[200005],nowr,nowl,ans;
char ch[200005];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1,x;i<=n;i++) {
        cin>>x>>ch[i];
        r[i]=r[i-1]+x,l[i]=r[i-1]+1;
    }
    nowr=r[n];
    for(int i=1;i<=n;i++){
        nowl=nowr-r[i]+l[i];
        int lid=lower_bound(r+1,r+1+n,nowl)-r,rid=lower_bound(r+1,r+1+n,nowr)-r;
        //cout<<nowl<<" "<<nowr<<" "<<lid<<" "<<rid<<endl;
        if(lid==rid){
            if(ch[lid]!=ch[i]) ans+=r[i]-l[i]+1;
        }else{
            if(ch[lid]!=ch[i]) ans+=r[lid]-nowl+1;
            if(ch[rid]!=ch[i]) ans+=nowr-l[rid]+1;
            for(int j=lid+1;j<=rid-1;j++){
                if(ch[j]!=ch[i]) ans+=r[j]-l[j]+1;
            }
        }
        nowr=nowl-1;
    }
    cout<<ans/2;
    return 0;
}
/*
5
3 a
7 b
2 e
2 b
4 a
*/
/*
i want to in the JS qirendashang
---limoxuan0712 uid:1432277
*/

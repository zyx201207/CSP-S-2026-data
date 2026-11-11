#include<bits/stdc++.h>
using namespace std;
struct KKK{
    int num;
    int len;
    int bit[33];
    bool ok;
}a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i].num;
        a[i].ok=1;
        int lenn=1,bb=a[i].num;
        while(bb>0){
            a[i].bit[lenn]=bb%2;
            bb/=2;
            lenn++;
        }
        a[i].len=lenn-1;
        //for(int j=1;j<=30;j++)cout<<a[i].bit[j];
        //cout<<'\n';
    }
    int res=0;
    for(int i=30;i>=1;i--){
        res*=2;
        int cnt=0;
        queue<int>del;
        for(int j=1;j<=n;j++){
            if(a[j].ok==false)continue;
            if(a[j].bit[i]==1){
                cnt++;
            }else{
                del.push(j);
            }
        }
        //cout<<cnt<<'\n';
        if(cnt>=m){
            res+=1;
            while(!del.empty()){
                int id=del.front();
                del.pop();
                a[id].ok=false;
            }
        }
    }cout<<res;
    return 0;
}
//Trick||Treat!

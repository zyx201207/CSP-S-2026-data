#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int a[2000005];
int f(int x,int y){
    int res=0;
    while(x<y){
        int cha=0;
        while(cha<=d && x<=y){
            cha+=a[x+1]-a[x];
            x++;
        }
        x--;
        res++;
    }
    return res;
}
bool is(int x,int y){
    int res=f(x,y);
    bool flg=0;
    for(int i=x+1;i<y;i++){
        if(f(x,i)+f(x+1,y)==res){
            if(!flg)flg=1;
            else return 0;
        }
    }
    if(!flg)return 0;
    return 1;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++)cin>>a[i];
        if(n<=3)cout<<0<<endl;
        else{
            for(int i=1;i<=n-3;i++){
                for(int j=3;i+j<=n;j++){
                    if(is(i,i+j))ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

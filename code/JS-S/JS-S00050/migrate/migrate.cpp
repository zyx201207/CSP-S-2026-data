#include<bits/stdc++.h>
using namespace std;
long long cccc,t,n,d;
bool flag1=1;
long long arr[2000002];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>cccc>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        long long gc=arr[2]-arr[1];
        for(int i=3;i<=n;i++){
            if(arr[i]-arr[i-1]!=gc){
                flag1=0;
                break;
            }
        }
        gc=d/gc;
        if(flag1){
            if(gc<=1)cout<<0;
            else cout<<n-gc-1<<endl;
        }
        else if(n<=3){
            cout<<0<<endl;
        }
        else if(n<=4){
            if(arr[3]-arr[1]<=d&&arr[4]-arr[3]<=d&&arr[4]-arr[2]<=d&&arr[2]-arr[1]<=d)cout<<1;
            else cout<<0;
        }
        else if(n<=5){
            int fa=0,ans=0;
            if(arr[4]-arr[1]<=d&&arr[5]-arr[4]<=d)fa++;
            if(arr[5]-arr[2]<=d&&arr[2]-arr[1]<=d)fa++;
            if(arr[5]-arr[3]<=d&&arr[3]-arr[1]<=d)fa++;
            if(fa==2)ans++;
            if(arr[3]-arr[1]<=d&&arr[4]-arr[3]<=d&&arr[4]-arr[2]<=d&&arr[2]-arr[1]<=d)ans++;
            if(arr[4]-arr[2]<=d&&arr[5]-arr[4]<=d&&arr[5]-arr[3]<=d&&arr[3]-arr[2]<=d)ans++;
            cout<<ans;
        }
        else cout<<n-gc+1;
    }
    //shang wu gu fen 100+100+60+0+eps=260+eps,hai you xi wang yi deng ma
    //mei you yi den wo jiu yao tui yi le
    //wo chang chang zhui yi guo qu
    //(hou mian bu hui bei le)
    //shun bian zai zhe fang ge dong xi xia ren
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    return 0;
}

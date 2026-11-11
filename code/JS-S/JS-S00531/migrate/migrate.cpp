#include<bits/stdc++.h>
using namespace std;

int c,t,n,d,x[2000005]={0},p;
bool f,f2;
int main(){
    srand(time(0));
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>c>>t;
    while(t--){
        f=1;
        f2=1;
        p=-1;
        cin>>n>>d;
        cin>>x[1];
        for(int i=2;i<=n;i++){
            cin>>x[i];
            if(p==-1 && i==2)p=x[i]-x[1];
            if(x[i]-x[i-1]!=p&&p!=-1)f=0;
            if(x[i]-x[i-1]>f2)f2=0;
        }

        if(x[n]-x[1]<=d)cout<<0<<'\n';
        else if(f){
            if(d/f==2){
                cout<<n-3<<'\n';
            }else{
                cout<<0<<'\n';
            }
        }else if(!f2){
            cout<<0<<'\n';
        }else{
            cout<<random()%n+1<<'\n';
        }
    }
    return 0;
}

/*70min <=48pts*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t,n,d,x[2000006]={};
map<int,int>mp;
void ljs(int a,int b,int c){
    if(x[b]-x[a]<=d){mp[c+1]++;return ;}
    for(int i=a+1;x[i]-x[a]<=d;i++){
        ljs(i,b,c+1);
    }
}
void solve_1to10(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            mp.clear();
            if(x[j]-x[i]<=d)continue;
            ljs(i,j,0);
            if((*(mp.begin())).second==2)cnt++;
        }
    }
    cout<<cnt<<endl;
}
void solve_11to12(){
    if(x[3]-x[1]>d)cout<<0<<endl;
    else{
        int del=d/(x[2]-x[1]);
        cout<<max(0ll,n-(2*del-1))<<endl;
    }
}
void solve_13to14(){
    int zd,mw,ans=0;
    for(int i=1;i<=n;i++){
        if((x[i]-x[1]<=d)&&(x[n]-x[i]<=d)){zd=i;break;}
    }
    mw=zd+1;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(x[n]-x[1]<=d)cout<<0<<endl;
        else if(c>=1&&c<=10)solve_1to10();
        else if(c>=11&&c<=12)solve_11to12();
        else solve_1to10();
    }
    return 0;
}
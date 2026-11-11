#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e3+35;
int pos[MAXN],n,d;
bool judge(int st,int en){
    int cnt=0;
    if(en-st+1==4){
        int temp1=pos[st],temp2=pos[st+1],temp3=pos[st+2],temp4=pos[en];
        if(temp4-temp1>d&&temp2-temp1<=d&&temp3-temp1<=d&&temp4-temp3<=d&&temp4-temp2<=d)return true;
        else return false;
    }
    for(int i=st;i<=en-4;i++){
        int temp1=pos[i],temp2=pos[i+1],temp3=pos[i+2],temp4=pos[i+3],temp5=pos[i+4];
        if(temp4-temp1>d&&temp2-temp1<=d&&temp3-temp1<=d&&temp4-temp3<=d&&temp4-temp2<=d&&temp5-temp3>d)cnt++;
    }
    if(cnt==1)return true;
    else return false;
}
bool valid(int st,int en){
    for(int i=st;i<en;i++){
        int temp1=pos[i],temp2=pos[i+1];
        if(temp2-temp1>d)return false;
    }
    return true;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)cin>>pos[i];
        int ans=0;
        for(int i=1;i<n-2;i++)
            for(int j=i+3;j<=n;j++)
                if(judge(i,j)&&valid(i,j))ans++;
        cout<<ans<<endl;
    }
    return 0;
}

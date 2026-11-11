#include<bits/stdc++.h>
#define int long long 
using namespace std;
const int kmaxn=2e6+10;
int idT,T;
int n,D,h[kmaxn],dp[kmaxn][5],qz[kmaxn][5];
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>idT>>T;
    while(T--){
        cin>>n>>D;
        for(int i=1;i<=n;i++){
            cin>>h[i];
            for(int j=0;j<5;j++)dp[i][j]=qz[i][j]=0;
            dp[i][0]=1;
        }
        /*
        1 221 111 2 11
        */
        int ans=0;
        int t1=1;//h[r+1]-h[i]<=D
        int t2=1;//h[r]-h[i]<=D
        int t3=2;//h[r]-h[i-1]<=D
        int t4=3;//h[r]-h[i-2]<=D
        int t5=2;//h[r-1]-h[i-1]<=D
        //[t,r-1]都是满足条件的
        for(int r=1;r<=n;r++){
            while(t1+1<=r&&h[r+1]-h[t1]>D)t1++;
            while(t2+1<=r&&h[r]-h[t2]>D)t2++;
            while(t3+1<=r&&h[r]-h[t3-1]>D)t3++;
            while(t4+1<=r&&h[r]-h[t4-2]>D)t4++;
            while(t5+1<=r&&h[r-1]-h[t5-1]>D)t5++;
            int tl=0,tr=0;
            if(r<n){//[t1,r-1]都continue
                tl=max(t1,t3);tr=min(r-1,t4-1);
                if(tl<=tr)ans+=(qz[tr][2]-qz[tl-1][2]);
                tl=max(t1,t2);tr=min(r-1,t3-1);
                if(tl<=tr)ans+=(qz[tr][3]-qz[tl-1][3]);
                tl=max({t1,t2,t3});tr=r-1;
                if(tl<=tr)ans+=(qz[tr][4]-qz[tl-1][4]);
            }
            if(r==n)t1=r;
            //从现在开始,tr=min(tr,t1-1)
            tl=t2;tr=t1-1;
            if(tl<=tr){
                if(r>1&&tr==r-1){
                    dp[r][4]+=dp[tr][0];tr--;
                }
                dp[r][2]+=(qz[tr][0]-qz[tl-1][0]);
            }
            tl=t2;tr=min({t1-1,t3-1,t5-1});
            if(tl<=tr){
                dp[r][2]+=(qz[tr][1]-qz[tl-1][1]);
                dp[r][2]+=(qz[tr][2]-qz[tl-1][2]);
                dp[r][2]+=(qz[tr][4]-qz[tl-1][4]);
            }
            tl=max(t2,t5);tr=min(t1-1,t3-1);
            if(tl<=tr){
                dp[r][1]+=(qz[tr][1]-qz[tl-1][1]);
                dp[r][1]+=(qz[tr][2]-qz[tl-1][2]);
                dp[r][1]+=(qz[tr][4]-qz[tl-1][4]);
            }
            tl=max(t2,t3);tr=min(t1-1,t4-1);
            if(tl<=tr)dp[r][3]+=(qz[tr][2]-qz[tl-1][2]);
            tl=t2;tr=min(t1-1,t3-1);
            if(tl<=tr)dp[r][3]+=(qz[tr][3]-qz[tl-1][3]);
            tl=max(t2,t3);tr=t1-1;
            if(tl<=tr)dp[r][3]+=(qz[tr][4]-qz[tl-1][4]);
            ans+=(dp[r][3]);
            for(int i=0;i<5;i++)qz[r][i]=(qz[r-1][i]+dp[r][i]);
        }
        cout<<ans<<"\n";
    }
    return 0;
}
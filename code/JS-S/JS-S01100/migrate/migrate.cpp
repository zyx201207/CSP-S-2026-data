#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define pii pair<long long,long long>
using namespace std;
int c,t,n;
long long d,a[2000005];
int nxt[2000005];
int L[2000005],R[2000005];
long long u[2000005][3];
long long b[2000005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    int qwq=0;
    while(t--){
        cin>>n>>d;
        qwq++;
        //cout<<n<<"???\n";
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        int l=1;
        L[1]=1;
        for(int i=1;i<=n;i++){
            while(l<n&&a[l+1]-a[i]<=d)R[l]=i-1,l++,L[l]=i;
            nxt[i]=l;
            //if(qwq==11)cout<<i<<" "<<nxt[i]<<"!!!\n";
        }
        R[n]=n;
        for(int i=1;i<=n;i++){
            //cout<<i<<" "<<L[i]<<" "<<R[i]<<"???\n";
            if(R[i]==i)R[i]--;
            for(int j=R[i];j>=L[i];j--){
                if(j==L[i])b[j]=0;
                else if(j==L[i]+1)b[j]=1;
                else b[j]=2;
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            u[i][0]=0;
            u[i][1]=0;
            u[i][2]=0;
            for(int j=L[i];j<=min(R[i],i-2);j++){
                u[i][0]+=u[j][0];
                u[i][1]+=u[j][1];
                u[i][2]+=u[j][2];
            }
            if(i>2)ans+=u[i][0]*(nxt[i-1]-nxt[i-2]);
            for(int j=max(L[i],min(R[i],i-2)+1);j<=R[i];j++){
                u[i][0]+=u[j][0];
                u[i][1]+=u[j][1];
                u[i][2]+=u[j][2];
            }
            if(i>1)ans+=u[i][1]*(nxt[i]-nxt[i-1]);
            if(b[i]==1)u[i][1]=u[i][0],u[i][0]=u[i][2]=0;
            if(b[i]==2)u[i][0]=u[i][1]=u[i][2]=0;
            if(b[i]==0){
                if(i>1&&nxt[i-1]==nxt[i]-1){
                    u[i][2]=u[i][0]+u[i][2];
                    u[i][0]=0;
                }else{
                    u[i][0]=u[i][0]+u[i][2];
                    u[i][2]=0;
                }
            }
            //cout<<i<<" "<<u[i][0]<<" "<<u[i][1]<<" "<<u[i][2]<<"!!!\n";
            //if(i>1&&nxt[i]!=i&&nxt[i-1]!=i-1&&nxt[nxt[i-1]]==nxt[nxt[i]])u[i][0]=0;
            u[i][0]++;
            //cout<<i<<" "<<ans<<"^^^\n";
        }
        cout<<ans<<"\n";
    }
    return 0;
}
//chennie bless me
//chennie bless me
//chennie bless me
//chennie bless me
//chennie bless me
//chennie bless me
//chennie bless me
//chennie bless me
//chennie bless me
//chennie bless me
//chennie bless me
//you jin bu liao WC le

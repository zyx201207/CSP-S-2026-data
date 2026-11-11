#include<bits/stdc++.h>
using namespace std;
long long n,c,t,a[2000005],d,q[200005],ans,mi,micnt;
bool dd[5005][5005],nod[5005][5005];
void dfs(int x,int mm,int dep){
    if(x==mm){
        if(dep<mi){
            mi=dep;
            micnt=1;
        }
        else{
            if(dep==mi){
                micnt++;
            }
        }
        return;
    }
    if(dep>mi){
        return;
    }
    for(int i=x+1;i<=mm;i++){
        if(a[i]-a[x]<=d){
            dfs(i,mm,dep+1);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c==1||c==2){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            ans=0;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    mi=100000,micnt=0;
                    dfs(i,j,0);
                    if(micnt==2){
                        ans++;
                    }
                }
            }
            cout<<ans<<"\n";
        }
        return 0;
    }
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            if(a[2]-a[1]>d){
                cout<<0<<"\n";
                //return 0;
                continue;
            }
            d/=(a[2]-a[1]);
            if(n<2*d||d==1){
                cout<<0<<"\n";
                continue;
            }
            else{
                ans=0;
                if(n>=2*d){
                    ans+=(n-2*d+1);
                }
                cout<<ans<<"\n";
                continue;
            }
        }
        return 0;
    }
    if(c==13||c==14){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            if(a[n]-a[1]<=d){
                cout<<"0\n";
                continue;
            }
            int cnt=0;
            for(int i=2;i<n;i++){
                cnt++;
            }
        }
        return 0;
    }
    while(t--){
        ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        //1 3 3 3 3 1
        //2 2 3 3 2 2
        //1,2,4,7,10,12,13,14
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                dd[i][j]=nod[i][j]=0;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                int pos=lower_bound(a+1,a+n+1,a[j]-d)-a;
                if(pos<j&&pos>i&&(a[pos]-a[i]<=d)&&(a[j]-a[i]<=d)){
                    for(int k=1;k<=i;k++){
                        for(int l=j;l<=n;l++){
                            if(!dd[k][l]&&(!nod[k][l])){
                                dd[k][l]=1;
                            }
                            else{
                                dd[k][l]=0;
                                nod[k][l]=1;
                            }
                        }
                    }
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                ans+=dd[i][j];
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
#define int ll

const int N=2e6+3;

int c,t;
int n,d;
int x[N];
int nxt[N];
int nd[N],cnt;

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>c>>t;
    if(c==11||c==12){
        while(t--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>x[i];
            }
            if(n<=3){
                cout<<"0\n";
                continue;
            }
            int dd=x[2]-x[1];
            if(dd*2>d){
                cout<<"0\n";
            }
            else{
                cout<<max(n-d/dd*2+1,0ll)<<'\n';
            }
        }
        return 0;
    }
    while(t--){
        cnt=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        if(n<=3){
            cout<<"0\n";
            continue;
        }
        for(int i=1;i<=n;i++){
            nxt[i]=upper_bound(x+i+1,x+n+1,x[i]+d)-x-1;
        }
        // for(int i=1;i<=n;i++){
        //     cout<<nxt[i]<<" ";
        // }
        // cout<<endl;
        for(int i=1;i<=n;i++){
            if(nxt[i]>2&&nxt[nxt[i]-1]>nxt[i]&&nxt[nxt[i]-2]<=nxt[i]){
                nd[++cnt]=nxt[i]-1;
            }
        }
        // for(int i=1;i<=cnt;i++)
        //     cout<<nd[i]<<" ";
        // cout<<endl;
        int ans=0;
        if(cnt==0){
            cout<<"0\n";
            continue;
        }
        for(int i=1,j=1;i<=n;i++){
            int lst=i;
            while(nxt[i]!=i)
                i=nxt[i];
            if(nd[j]<i){
                while(j<cnt&&nd[j]<lst)
                    j++;
                if(j==cnt){
                    if(nd[j]>lst){
                        ans+=(nd[j]-lst)*(i-nd[j]-1);
                    }
                    break;
                }
                if(nd[j]>i)
                    continue;
                int t1=nd[j]-lst;
                int t2=0;
                while(j<cnt&&nd[j+1]<i){
                    j++;
                    t2=nd[j]-nd[j-1];
                    ans+=t1*t2;
                    t1=t2;
                }
                t2=i-nd[j]-1;
                ans+=t1*t2;
            }
        }
        cout<<ans<<'\n';
    }
    cout<<flush;
    return 0;
}
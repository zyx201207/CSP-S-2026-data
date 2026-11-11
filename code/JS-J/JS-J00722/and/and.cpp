#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int> digit[100];
int cnt[100]{};
int maxx=-1e5;
int a[200005]{};
int ans=0,max_dig=0;
int n,m;
int now=0;
int can[200005]{};
void next(){
    int tmp=0;
    memset(can,sizeof(can),0);
    while(!digit[now].empty()){
        can[++tmp]=digit[now].back();
        digit[now].pop_back();
    }
        for(int i=now-1;i>0;--i){
            for(int j=1;j<=tmp;++j){
                if((a[can[j]]/(1<<(i-1)))%2==1){
                    digit[i].push_back(can[j]);
                    cnt[i]++;
                }
            }
            now=i;
            if(cnt[i]>=m){
                ans+=1<<(i-1);

               // cout<<i<<endl;
                break;
        }
    }
    return;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>a[i];
        maxx=max(maxx,a[i]);
    }
    if(m==1){
        cout<<maxx;
        return 0;
    }
    else if(m==n){
        int an=a[1]&a[2];
        for(int i=1;i<=n;++i){
            an&=a[i];
            if(an==0){
                cout<<0;
                return 0;
            }
        }
    }
    int tmp=maxx;
    while(tmp){
        tmp/=2;
        max_dig++;
    }

    for(int i=max_dig;i>0;--i){
        for(int j=1;j<=n;++j){
            if((a[j]/(1<<(i-1)))%2==1){
                digit[i].push_back(j);
                cnt[i]++;
            }
        }
        now=i;
        if(cnt[i]>=m){
            ans+=1<<(i-1);
            now=i;
        //    cout<<i<<endl;
            break;
        }
    }
    while(now>1){
        next();
    }
    cout<<ans;
    return 0;
}

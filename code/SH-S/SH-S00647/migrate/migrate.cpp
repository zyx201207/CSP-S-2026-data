#include<bits/stdc++.h>
//Things will always be better, just let time plays
using namespace std;
#define HACKILLER_FAST ios::sync_with_stdio(false),cin.tie(0)
#define int long long
#define ull unsigned long long
#define vc vector
#define pii pair<int,int>
#define pb push_back
#define ls x<<1
#define rs x<<1|1
int id,T,n,d,a[2000050],pre[2000050],nxt[2000050],cnt[2000050];

signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    HACKILLER_FAST;
    cin>>id>>T;
    while(T--){
        for(int i = 1;i <= n;++i) cnt[i] = 0;
        for(int i = 1;i <= n;++i) pre[i] = nxt[i] = i;
        cin>>n>>d;
        for(int i = 1;i <= n;++i) cin>>a[i];
        for(int i = 1;i <= n;++i){
            int l = 1,r = i;
            while(l <= r){
                int mid = l+r>>1;
                if(a[mid] >= a[i]-d) pre[i] = mid,r = mid-1;
                else l = mid+1;
            }
        }
        for(int i = 1;i <= n;++i){
            int l = i,r = n;
            while(l <= r){
                int mid = l+r>>1;
                if(a[mid] <= a[i]+d) nxt[i] = mid,l = mid+1;
                else r = mid-1;
            }
        }
        //for(int i = 1;i <= n;++i) cerr<<pre[i]<<' '<<nxt[i]<<'\n';
        for(int i = 1;i <= n;++i){
            cnt[i] = cnt[i-1];
            int res = 0,lst = pre[i];
            for(int j = pre[i];j >= 1;j = pre[j]){
                //cerr<<j<<' '<<i<<'\n';
                //if(pre[j] == pre[j+1] && pre[j] == pre[j+2]) break;
                //if(pre[j] == pre[j+1] && min(i,nxt[j]) != min(i,nxt[j+1])) break;
                //if(pre[j] == pre[j+1]) ++res;
                if(res == 1){
                    //cerr<<j<<' '<<i<<'\n';
                    ++cnt[i];
                    if(n <= 300){
                        for(int k = j+1;k < lst;++k){
                            if(min(i,nxt[j]) != min(i,nxt[k])) break;
                            ++cnt[i];
                            //cerr<<k<<' '<<i<<'\n';
                        }
                    }
                    else{
                        int l = j+1,r = lst-1,ress = 0;
                        while(l <= r){
                            int mid = l+r>>1;
                            if(min(i,nxt[j]) == min(i,nxt[mid])) ress = mid-j,l = mid+1;
                            else r = mid-1;
                        }
                        cnt[i]+=ress;
                    }
                }
                else{
                    if(n <= 300){
                        for(int k = j+1;k < lst;++k){
                            if(nxt[j] != nxt[k]){
                                if(nxt[k]-nxt[j] > 1) break;
                                if(min(i,nxt[nxt[k]]) != min(i,nxt[nxt[j]])) break;
                                ++cnt[i];
                                //cerr<<k<<' '<<i<<'\n';
                            }
                        }
                    }
                    else{
                        int l = j+1,r = lst-1,ress = 0;
                        while(l <= r){
                            int mid = l+r>>1;
                            if(nxt[j] == nxt[mid]) l = mid+1;
                            else if(nxt[mid]-nxt[j] > 1) r = mid-1;
                            else if(min(i,nxt[nxt[j]]) == min(i,nxt[nxt[mid]])) ress = mid,l = mid+1;
                            else r = mid-1;
                        }
                        l = j+1,r = lst-1;
                        int resss = j;
                        while(l <= r){
                            int mid = l+r>>1;
                            if(nxt[j] == nxt[mid]) resss = mid,l = mid+1;
                            else r = mid-1;
                        }
                        cnt[i]+=max(0LL,ress-resss);
                    }
                }
                if(pre[j] == j) break;
                lst = j;
                if(pre[j] == pre[j+1] && pre[j] == pre[j+2]) break;
                if(pre[j] == pre[j+1] && min(i,nxt[j]) != min(i,nxt[j+1])) break;
                if(pre[j] == pre[j+1]) ++res;
                if(res >= 2) break;
            }
            //cerr<<i<<' '<<cnt[i]<<'\n';
        }
        cout<<cnt[n]<<'\n';
    }
    return 0;
}
//ForEverLOVE

#include<bits/stdc++.h>
using namespace std;
#define ll long long

struct S{
    int n;
    char c;
    void in(){
        cin>>n>>c;
    }
    int erase(){
        int m=n;
        n=0;
        return m;
    }
};

struct Sl{
    ll n;
    char c;
    void in(){
        cin>>n>>c;
    }
    ll erase(){
        ll m=n;
        n=0;
        return m;
    }
};

void solve(){
    int n;
    cin>>n;
    if(n>100000){
        S sfi[n];
        for(int i=0;i<n;i++){
            sfi[i].in();
        }
        int cnt=n;
        // cerr<<"重复{";
        int j0=0;
        for(int i=1;i<n;i++){
            if(sfi[i].c==sfi[j0].c){
                sfi[j0].n+=sfi[i].erase();
                // cerr<<i<<',';
                cnt--;
            }else{
                j0=i;
            }
        }
        // cerr<<"}\n\n";
        // cerr<<"cnt:"<<cnt<<'\n';
        S s[cnt],rs[cnt];
        int j1=0;
        // cerr<<"s:{\n";
        for(int i=0;i<cnt;i++){
            while(j1<n&&!sfi[j1].n){
                j1++;
            }
            if(j1>n){
                break;
            }
            s[i].n=sfi[j1].n;
            s[i].c=sfi[j1].c;
            rs[cnt-i-1].n=sfi[j1].n;
            rs[cnt-i-1].c=sfi[j1].c;
            // cerr<<s[i].n<<' '<<s[i].c<<'\n';
            j1++;
        }
        // cerr<<"}\n";
        int ans=0;
        for(int i=0;i<cnt;){
            for(int j=0;j<cnt;){
                if(s[i].c==rs[j].c){
                    if(s[i].n==rs[j].n){
                        i++;
                        j++;
                    }else if(s[i].n>rs[j].n){
                        s[i].n-=rs[j++].n;
                    }else{
                        rs[j].n-=s[i++].n;
                    }
                }else{
                    if(s[i].n==rs[j].n){
                        ans+=s[i].n;
                        i++;
                        j++;
                    }else if(s[i].n>rs[j].n){
                        ans+=rs[j].n;
                        s[i].n-=rs[j++].n;
                    }else{
                        ans+=s[i].n;
                        rs[j].n-=s[i++].n;
                    }
                }
            }
        }
        // cerr<<"ans:"<<ans/2<<'\n';
        cout<<ans/2;
        return;
    }else{
        Sl sfi[n];
        for(int i=0;i<n;i++){
            sfi[i].in();
        }
        int cnt=n;
        cerr<<"重复{";
        int j0=0;
        for(int i=1;i<n;i++){
            if(sfi[i].c==sfi[j0].c){
                sfi[j0].n+=sfi[i].erase();
                cerr<<i<<',';
                cnt--;
            }else{
                j0=i;
            }
        }
        cerr<<"}\n\n";
        cerr<<"cnt:"<<cnt<<'\n';
        Sl s[cnt],rs[cnt];
        int j1=0;
        cerr<<"s:{\n";
        for(int i=0;i<cnt;i++){
            while(j1<n&&!sfi[j1].n){
                j1++;
            }
            if(j1>n){
                break;
            }
            s[i].n=sfi[j1].n;
            s[i].c=sfi[j1].c;
            rs[cnt-i-1].n=sfi[j1].n;
            rs[cnt-i-1].c=sfi[j1].c;
            cerr<<s[i].n<<' '<<s[i].c<<'\n';
            j1++;
        }
        cerr<<"}\n";
        ll ans=0;
        for(int i=0;i<cnt;){
            for(int j=0;j<cnt;){
                if(s[i].c==rs[j].c){
                    if(s[i].n==rs[j].n){
                        i++;
                        j++;
                    }else if(s[i].n>rs[j].n){
                        s[i].n-=rs[j++].n;
                    }else{
                        rs[j].n-=s[i++].n;
                    }
                }else{
                    if(s[i].n==rs[j].n){
                        ans+=s[i].n;
                        i++;
                        j++;
                    }else if(s[i].n>rs[j].n){
                        ans+=rs[j].n;
                        s[i].n-=rs[j++].n;
                    }else{
                        ans+=s[i].n;
                        rs[j].n-=s[i++].n;
                    }
                }
            }
        }
        cerr<<"ans:"<<ans/2<<'\n';
        cout<<ans/2;
        return;
    }
}

signed main(){
    clock_t st=clock();

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0),cerr.tie(0);

    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    cerr<<"\n\n\n\n耗时:"<<(double)(clock()-st)*1000/CLOCKS_PER_SEC<<"ms";
}


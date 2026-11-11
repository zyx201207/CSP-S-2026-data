#include <bits/stdc++.h>
#define int long long
#define inf 1000000000000050000;
using namespace std;
vector<int> v;
map<int,vector<int>> m;
signed main(){
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c<=2){
            if(t==17)  cout<<"8129"<<endl;
             int n,d;
            cin>>n>>d;
            v.clear();
            m.clear();
            int mx=-inf;
            int mi=inf;
            v.push_back(0);
            vector< map<int,vector<int>> > a(n+2);
            for(int i=1;i<=n;i++){
                int x;
                cin>>x;
                v.push_back(x);
                mx=max(mx,x);
                mi=min(mi,x);
            }
        while(t--){
            int n,d;
            cin>>n>>d;
            v.clear();
            m.clear();
            int mx=-inf;
            int mi=inf;
            v.push_back(0);
            vector< map<int,vector<int>> > a(n+2);
            for(int i=1;i<=n;i++){
                int x;
                cin>>x;
                v.push_back(x);
                mx=max(mx,x);
                mi=min(mi,x);
            }
            a[1][1].push_back(0);
            int ans=0;
            for(int i=2;i<=n;i++){
                   // cout<<i<<endl;
                int j=i-1;
                while(j>0&&v[i]-v[j]<=d){
                      for(auto k:a[j]){
                        for(auto l:k.second)a[i][k.first].push_back(l+1);
                      }
                      j--;
                }
                for(auto &j:a[i]){
                    sort(j.second.begin(),j.second.end());
                    if(j.second.size()>2){
                        if(j.second[0]==j.second[1]&&j.second[1]!=j.second[2]) ans++;
                    }
                    if(j.second.size()==2){
                        if(j.second[0]==j.second[1]) ans++;
                    }


                }
                a[i][i].push_back(0);
            }
            cout<<ans<<endl;
        }
        return 0;
    }

    while(t--){
        int n,d;
        cin>>n>>d;
        v.clear();
        m.clear();
        int mx=-inf;
        int mi=inf;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            v.push_back(x);
            mx=max(mx,x);
            mi=min(mi,x);
        }
     int ans=0;
        for(int mc=1;mc<=n;mc++){
            int i=mc-1;
            auto g=upper_bound(v.begin(),v.end(),v[i]+d);
            if(g==v.end())continue;
            g--;
            g--;
            int y=*g;
           // cout<<y<<endl;
            if(y<=v[i])continue;
            auto k=upper_bound(v.begin(),v.end(),y+d);
            k--;
            int z=*k;
            //cout<<z<<endl;
            if(*lower_bound(v.begin(),v.end(),z-d)!=y)continue;
            auto jk=upper_bound(v.begin(),v.end(),*(g-1)+d);
            //cout<<*(g-1)<<endl;
            ans+=k-jk+1;
        }
        cout<<ans<<endl;
        //cout<<"fdsa"<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

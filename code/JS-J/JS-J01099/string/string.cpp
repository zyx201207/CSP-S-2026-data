#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin>>n;
  //  cout<<n<<endl;
    //  vector<ll> sum(n+3);
    vector<pair<long long,char>> p(n+3);
    for(int i=1;i<=n;++i) cin>>p[i].first>>p[i].second;

    long long x=n,y=0;//?
  //  cout<<n<<endl;
    long long ans=0;
    for(int i=1;i<=n;++i){
      //  cout<<"fdsvfdsjgvnds"<<endl;
        long long k=p[i].first;
        while(k>0&&x>0){
            if(p[x].first-y<=k){
                k-=(p[x].first-y);
                if(p[i].second!=p[x].second) ans+=(p[x].first-y);
                --x;
                y=0;
                
            }else{
                if(p[i].second!=p[x].second) ans+=k;
                y+=k;
                k=0;
            }
        }
       // cout<<x<<y<<endl;
    }

    cout<<ans/2<<endl;  
  
    return 0;
}
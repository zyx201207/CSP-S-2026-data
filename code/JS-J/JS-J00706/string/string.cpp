#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
   freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string f;
    vector<pair<char,long long> >v(n+1);
    for(int i=1;i<=n;i++){
        long long a;char c;
        cin>>a>>c;
        v[i].first=c;
        v[i].second=a;
    }
    long long ans=0;
    long long l=0,r=f.size()-1;
    int l_c=1,r_c=n;
    while(l_c<r_c){
        if(v[l_c].first!=v[r_c].first){
            long long min_v=min(v[l_c].second,v[r_c].second);
            ans+=min_v;
           // printf("\n%d",min_v);
            v[l_c].second-=min_v;v[r_c].second-=min_v;
            if(v[l_c].second<=0){
                l_c++;
            }else r_c--;
        }else{
            long long min_v=min(v[l_c].second,v[r_c].second);
            v[l_c].second-=min_v;v[r_c].second-=min_v;
            //printf("\n%d",min_v);
            if(v[l_c].second<=0){
                l_c++;
            }else r_c--;
        }

    }
    cout<<ans;

}

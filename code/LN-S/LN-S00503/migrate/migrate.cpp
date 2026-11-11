#include <bits/stdc++.h>

using namespace std;
struct node{
    int zuo,low,cnt;
};
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
       int n,m;
        cin>>n>>m;
        vector<node>a;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            a.push_back({x,INT_MAX,0});
        }
        a[0].low=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(a[j].zuo-a[i].zuo>m)break;
                a[j].low=min(a[i].low+1,a[j].low);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(a[i].zuo-a[j].zuo>m)break;
                if(a[j].low+1==a[i].low)a[i].cnt++;
            }
        }
        int countc=0;
        for(int i=0;i<n;i++){
            if(a[i].cnt==2)countc++;
        }
        cout<<countc<<endl;
    }


    return 0;
}

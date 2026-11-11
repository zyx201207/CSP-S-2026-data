#include <bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans,num[200005][33];
vector<int> sum[33],anss;
void init(){
    for(int i=1;i<=n;i++){
        int x=a[i],j=1;
        while(x!=0){
            num[i][j]=x%2;
            if(x%2==1) sum[j].push_back(i);
            x/=2;
            j++;
        }
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    init();
    int d=1;
    for(int i=32;i>=1;i--){
        if(anss.size()==m) break;
        if(sum[i].size()>=m){
            if(d){
                for(int j:sum[i]) anss.push_back(j);
                d=0;
            }
            else{
                int x=0;
                for(int j:anss){
                    if(num[j][i]) x++;
                }
                if(x>=m){
                    int j=0;
                    while(j<anss.size()){
                        if(!num[anss[j]][i]) anss.erase(j+anss.begin());
                        else j++;
                    }
                }
            }
        }
    }
    ans=a[anss[0]];
    for(int i=1;i<m;i++) ans&=a[anss[i]];
    cout<<ans;
    return 0;
}

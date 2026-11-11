#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    std::cin.tie(0);
    std::cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;cin>>n>>m;
    vector<vector<int> >mask(n,vector<int>(31,0));
    vector<int>aa(n);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        aa[i]=a;
        int j=0;
        while(a>0){
            int cur=a%2;
            mask[i][j]=cur;
            a/=2;
            j++;
        }
    }
    vector<int>cho(n,1);
    for(int i=31;i>=0;i--){
        int cnt=0;
        for(int j=0;j<n;j++){
            if(cho[j]==0)continue;
            if(mask[j][i])cnt++;
        }
        if(cnt>=m){
            for(int j=0;j<n;j++){
                if(!cho[j])continue;
                if(!mask[j][i])cho[j]=0;
            }
        }
    }
    ll ans=(1<<31)-1;
    for(int i=0;i<n;i++){
        if(cho[i])ans=ans&aa[i];
    }
    cout<<ans;
    return 0;
}



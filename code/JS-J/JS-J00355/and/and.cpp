#include <bits/stdc++.h>
using namespace std;
int main(){
    #define int long long
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n,0);
    vector<int> cnt_at_this_bit(33,0);
    unordered_map<int,bool> reduced;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        a[i]=tmp;
        for(int i=1,k=0;i<=tmp;i<<=1,k++){
            int ci=i;
            if((tmp&ci)!=0){
                cnt_at_this_bit[k]++;
            }
            //cerr<<"[debug] "<<"read "<<tmp<<" testing on bit "<<k<<" ,result="<<(tmp&ci)<<endl;
        }
    }
    int ans=0;
    for(int k=32;k>=0;k--){
        if(cnt_at_this_bit[k]<m){
            continue;
        }
        for(size_t i=0;i<a.size();i++){
            int cur=a[i];
            if(((cur&(1<<k))==0)&&(reduced[cur]==0)){
                reduced[cur]=1;
                for(int j=1,k2=0;j<=cur;j<<=1,k2++){
                    int ci=j;
                    if((cur&ci)!=0){
                        cnt_at_this_bit[k2]--;
                    }
                }
            }
        }
        ans+=(1<<k);
    }
    cout<<ans<<endl;
    #undef int
    return 0;
}
// ________  ________ 
//|  ____  ||  ____  |   __      __     __
//| |____| || |____| | _|  |_  _|  |_  |__|
//|   __   ||  ______||_    _||_    _|  __
//|__|  \__\|_|         |__|    |__|   |_/
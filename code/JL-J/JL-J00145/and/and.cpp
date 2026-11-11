#include <bits/stdc++.h>
using namespace std;
typedef struct date{
    int num;
    bool tf;
};
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,cnt=0;
    cin>>n>>m;
    vector<vector<int>>dp(31,vector<int>(200001,0)),num(31);
    for(int i=1;i<=n;i++){
        int a,j=0;
        cin>>a;
        while(a>0){
            int s=a%2;
            if(s==1){
                dp[j][i]=1;
                num[j].push_back(i);
            }
            j++;
            a/=2;
        }
    }vector<date>tf;
    for(int i=30;i>=0;i--){
        if(num[i].size()>=m){
            if(tf.size()==0){
                cnt+=pow(2,i);
                for(int j=0;j<num[i].size();j++){
                    tf.push_back({num[i][j],true});
                }
            }else{
                int cnt1=0;
                for(int j=0;j<=tf.size();j++){
                    if(dp[i][tf[j].num]==1 && tf[j].tf) cnt1++;
                }if(cnt1>=m){
                    cnt+=pow(2,i);
                    for(int j=0;j<=tf.size();j++){
                        if(dp[i][tf[j].num]==0) tf[j].tf=false;
                    }
                }

            }

        }
    }cout<<cnt<<endl;
    return 0;
}

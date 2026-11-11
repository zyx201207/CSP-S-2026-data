#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,d;

bool f1(vector<int> a,int l,int r){
    vector<int> dp(n,0);
    dp[l]=1;

    while(l!=r){
        l++;
        for(int j=l-1;j>0;j++){
            if(a[l]-a[j]<=d){
                dp[l]+=dp[j];
            }
            else{break;}
        }

    }
    if(dp[r]==2){

            return false;
        }return true;
}


void solve1(vector<int> a){
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(!f1(a,i,j))ans++;
        }
    }
    cout<<ans-2<<endl;




}





int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        vector<int>a;
        for(int i=0;i<n;i++){
            int x;cin>>x;
            a.push_back(x);
        }
        solve1(a);






    }



}


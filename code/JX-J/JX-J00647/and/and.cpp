#include<bits/stdc++.h>
using namespace std;
vector<int> ve(200000+5,0);
vector<bool> gy(200000+5,true);
int ans=INT_MIN;
void dfs(int a,int b,int t,int sum){
if(a>b){
    ans=max(ans,sum);
}
         for(int i=1;i<=t;i++){
            if(gy[i]){
            gy[i]=false;
            if(a==1){
                dfs(a+1,b,t,ve[i]);
            }else{
            dfs(a+1,b,t,(sum&ve[i]));
            }
            gy[i]=true;
        }

    }
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
int a,b;
cin>>a>>b;
for(int i=1;i<=a;i++){
    cin>>ve[i];
    }
dfs(1,b,a,0);
cout<<ans;
return 0;
}

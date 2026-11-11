#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,sum=0;string ans;
    cin>>n;
    for(int i=1;i<=n;i++){
    int x;
    cin>>x;
    char a;
    cin>>a;
        for(int i=1;i<=x;i++){
           ans+=a;
        }
    }int as=ans.size();
    for(int i=0;i<as;i++){
       if(ans[i]==ans[as]){
       sum+=0;
       }else{
       sum++;
       }as--;
    }
    cout<<sum;
    return 0;
}

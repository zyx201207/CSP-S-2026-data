#include<bits/stdc++.h>
using namespace std;
int m,n;
int s[200001],sum=0;
int p(int y){
    int ans;
    ans=1;
    for(int j=1;j<=y;j++){
        ans*=2;
    }
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>s[i];
    }
    int pw;
    for(int w=30;w>=0;w--){
        int g=0;
        pw=p(w);
        for(int i=1;i<=m;i++){
            if(pw<=s[i]){
                g++;
            }
        }
        if(g>=n){
            for(int i=1;i<=m;i++){
                if(pw<s[i]){
                    s[i]-=pw;
                }
                else {
                    s[i]=0;
                }
            }
            sum+=pw;
        }
        else {
            for(int i=1;i<=m;i++){
                if(pw<s[i]){
                    s[i]-=pw;
                }
            }
        }
    }
    cout<<sum;
    return 0;
}

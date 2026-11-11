#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long a,b[200005],ans=0,maxb=0,sumb=0;
    char c[200005];
    string e;
    cin>>a;
    for(int i=1;i<=a;i++){
        cin>>b[i]>>c[i];
        maxb=max(maxb,b[i]);
        sumb+=b[i];
        for(int j=1;j<=b[i];j++){
            e+=c[i];
        }
    }
    if(maxb<=10000){
        if(e.size()%2==0){
            for(int i=0;i<=e.size()-1;i++){
                int j=e.size()-i-1;
                if(i==j+1){
                    break;
                }
                if(e[i]!=e[j]){
                    ans++;
                }
            }
        }else{
            for(int i=0;i<=e.size()-1;i++){
                int j=e.size()-i-1;
                if(i==j){
                    break;
                }
                if(e[i]!=e[j]){
                    ans++;
                }
            }
        }
    }else{
        cout<<sumb/2;
        return 0;
    }
    cout<<ans;
    return 0;
}

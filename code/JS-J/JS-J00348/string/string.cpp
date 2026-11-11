#include<bits/stdc++.h>
using namespace std;
int n,x,ans=0;
string y,s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    while(n--){
        cin>>x>>y;
        for(int i=1;i<=x;i++){
            s+=y;
        }
    }
    if(s.size()%2){
        for(int i=0,k=s.size()-1;i<=s.size()/2,k>=s.size()/2+1;i++,k--){
            if(s[i]!=s[k]){
                ans++;
            }
        }
    }else{
        for(int i=0,k=s.size()-1;i<=s.size()/2-1,k>=s.size()/2;i++,k--){
            if(s[i]!=s[k]){
                ans++;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}

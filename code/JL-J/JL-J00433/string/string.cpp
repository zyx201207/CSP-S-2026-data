#include<bits/stdc++.h>
using namespace std;
int t,n,cnt=0,j=0;
char f;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--){
        cin>>n>>f;
        for(int i=1;i<=n;i++){
            s+=f;
        }
    }
    j=s.size();
    if(s.size()%2==0){
        for(int i=1;i<=s.size()/2;i++){
            if(s[i]!=s[j]){
                cnt++;
            }
            j--;
        }
    }
    else{
        j--;
        for(int i=1;i<=s.size()/2+1;i++){
            if(s[i]!=s[j]){
                cnt++;
            }
            j--;
        }
    }
    cout<<cnt;
    return 0;
}

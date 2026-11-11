#include<bits/stdc++.h>
using namespace std;
int n,k;
long long ans;
struct node{
    int a;
    char c;
};
string s;
vector<node>b(200010);
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>b[i].a>>b[i].c;
        ans+=b[i].a;
    }
    if(ans%2){
        ans=ans/2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=b[i].a;j++){
                s=s+b[i].c;
            }
        }
        for(int i=0;i<ans;i++){
            if(s[i]!=s[s.size()-1-i]){
                k++;
            }
        }
    }else{
        ans=ans/2;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=b[i].a;j++){
                s=s+b[i].c;
            }
        }
        for(int i=0;i<ans;i++){
            if(s[i]!=s[s.size()-1-i]){
                k++;
            }
        }
    }
    cout<<k;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    vector<char> s,w;
    if(n==1){
        cout<<0;
        return 0;
    }
    int a,c;
    for(int i=0;i<n;i++){
        cin>>a>>c;
        while(a--){
            s.push_back(c);
        }
    }
    for(int i=s.size()-1;i>=0;i--){
        w.push_back(s[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]!=w[i])ans++;
    }
    cout<<ans;
    return 0;
}

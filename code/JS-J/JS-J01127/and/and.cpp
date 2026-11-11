#include <bits/stdc++.h>
using namespace std;
//#define debug
vector <pair<char,long long> > as;
int main(){
#ifndef debug
freopen("and.out","w",stdout);
freopen("and.in","r",stdin);
#endif
    int n,m;
    cin>>n>>m;
    vector<int> ans;
    for(int _=0;_<n;_++){
        int t;
        cin>>t;
        ans.push_back(t);
    }
    int maxx=1ll<<30;
    while (maxx>0){
        vector<int> temp;
        for(auto i:ans){
            if(i&maxx) temp.push_back(i);
        }
        if(temp.size()<m) {
            maxx>>=1;
            continue;
        }
        ans=temp;
        maxx>>=1;
    }
    int anss=ans[0];
    for(auto i:ans){
        anss&=i;
    }
    cout<<anss;
#ifndef debug
fclose(stdout);
fclose(stdin);
#endif
    return 0;
    }

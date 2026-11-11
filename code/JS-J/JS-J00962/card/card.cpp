#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>s(n),k(m);
    for(int i=0;i<n;i++){
        cin>>s[i];
        s[i]--;
    }
    for(int i=0;i<n;i++){
        vector<int>l(m),r;
        for(int j=i;j<n;j++){
            if(l[s[j]]==0){
                r.push_back(s[j]);
                l[s[j]]++;
            }
            else{
                while(r[r.size()-1]!=s[j]){
                    l[r[r.size()-1]]-=1;
                    r.pop_back();
                }
            }
        }
        for(int i=0;i<r.size();i++){
            k[r[i]]++;
        }
    }
    for(int i=0;i<m;i++){
        cout<<k[i]<<' ';
    }
    return 0;
}

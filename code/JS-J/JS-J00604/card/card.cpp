#include<bits/stdc++.h>
using namespace std;
vector<int>tt,pl,ans;
int n,m,a;
bool atest=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >>n>>m;
    pl.resize(m+1);
    ans.resize(m+1);
    for(int i=0;i<n;i++){
        cin >>a;
        if(i!=0&&a<tt.back()){
            atest=0;
        }
        tt.push_back(a);
        pl[a]=i;
    }
    if(atest){
        for(int i=1;i<n;i++){
            if(tt[i]!=tt[i-1]){
                ans[tt[i-1]]=i;
            }
        }
    }
    else {

    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            ans[tt[j]]++;
            if(pl[tt[j]])j=pl[tt[j]];
        }
    }
    }
    for(int i=1;i<=m;i++)cout <<ans[i]<<" ";
    return 0;
}

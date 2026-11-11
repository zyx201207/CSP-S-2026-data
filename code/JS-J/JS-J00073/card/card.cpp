#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>a,ans;
void solve(int x){
    deque<int>b;
    for(int i=n-x;i<n;i++){
        b.push_back(a[i]);
    }
    deque<int>desk;
    map<int,int>place;
    while(!b.empty()){
        int cert=b[0];
        b.pop_front();
        if(place.find(cert)!=place.end()&&place[cert]!=-1){
            while(desk[desk.size()-1]!=cert){
                place[desk[desk.size()-1]]=-1;
                desk.pop_back();
            }
            place[desk[desk.size()-1]]=-1;
            desk.pop_back();
        }
        desk.push_back(cert);
        place[cert]=desk.size()-1;
        for(int i=0;i<desk.size();i++){
            cout<<desk[i]<<" ";
        }
        cout<<endl;
    }
    for(int i=0;i<desk.size();i++){
        ans[desk[i]]+=1;
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    a.resize(n);
    ans.resize(m+2);
    for(int i=0;i<m;i++){
        ans[i]=0;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
        solve(n-i);
    for(int i=1;i<=m;i++){
        cout<<ans[i];
        if(i!=m)
            cout<<" ";
    }
    return 0;
}

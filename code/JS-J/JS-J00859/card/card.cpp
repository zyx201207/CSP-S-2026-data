#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);  
    int n,m;
    cin>>n>>m;
    map<int,int>mp;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        deque<int>dq;
        set<int>s;
        for(int j=i;j<=n;j++){
            if(s.count(a[j])){
                while(dq.back()!=i){
                    s.erase(dq.back());
                    dq.pop_back();
                }
            }
            else {
                s.insert(a[j]);
                dq.push_back(a[j]);
            }
        }
        while(dq.size()){
            mp[dq.back()]++;
            dq.pop_back();
        }
    }
    for(int i=1;i<=m;i++)cout<<mp[i]<<" ";
    return 0;
}
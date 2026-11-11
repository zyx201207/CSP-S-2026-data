#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n=0,m=0;
    cin>>n>>m;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int index=0;
   unordered_map <int,int> mp;

    while(index<n){
    unordered_map <int,int> group;
    for(int i=index;i<n;i++){
        if(group[arr[i]]>=1){
            group.clear();
            group[arr[i]]=1;
        }else{
        group[arr[i]]=1;
        }
      }
      for(auto &p:group){
        mp[p.first]++;
      }
      index++;
    }
    for(int i=1;i<=m;i++){
        cout<<mp[i]<<" ";
    }




    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> save(m+1,0);
    for(int start=1;start<=n;start++){
        vector<int> u(n+1,0);
        for(int i=start;i<=n;i++){
            if(a[i]==u.back()){
                save[a[i]]--;
                u.pop_back();
            }else{
                u.push_back(a[i]);
                save[a[i]]++;
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<save[i]<<" ";
    return 0;
}

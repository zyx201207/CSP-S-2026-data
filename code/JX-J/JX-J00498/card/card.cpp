#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    vector<int>a;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>i;
        if(a.find(i)==1){
            for(int i=a.find(i);i<=a.size();i++){
                a.erase(i);
            }
            a[i]=i;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i];
    }
    return 0;
}

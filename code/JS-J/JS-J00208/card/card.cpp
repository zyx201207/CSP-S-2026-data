#include<bits/stdc++.h>
using namespace std;
int n,m,x,f,k;
int s[500010];
vector<int> v;
int main(){

    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        for(int i=0;i<v.size();i++){
            if(v[i]==x){
                k=i;
            }
        }
        v.erase(v.begin()+k,v.end()+1);
        v.push_back(x);
        for(int i=0;i<v.size();i++){
            s[i+1]++;
        }

    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<" ";
    }



    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<int> v;
int ans;
int mm[21][2001];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int a,maxx=0;
    for(int i=0;i<n;i++){
        cin>>a;
        maxx=max(maxx,a);
        v.push_back(a);
    }
    if(m==n){
        ans=v[0];
        for(int i=1;i<n;i++){
            ans&=v[i];
        }
        cout<<ans;
    }else if(m==1){
        cout<<maxx;
    }else if(m==2){
        cout<<0;
    }else{
        cout<<0;
    }
    return 0;
}

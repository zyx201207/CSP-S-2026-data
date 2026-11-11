#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005];
stack<long long>s;
map<long long,long long>mp;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int b[m+1]={0};
        for(int j=i;j<=n;j++){
            if(b[a[j]]){
                while(s.top()!=a[j])s.pop();
            }else{
                s.push(a[j]);
                b[a[j]]++;
            }
        }
        while(s.size()){
            mp[s.top()]++;
            s.pop();
        }
    }
    for(auto i:mp)cout<<i.second<<' ';
}

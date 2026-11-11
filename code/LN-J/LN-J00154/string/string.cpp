#include <bits/stdc++.h>
using namespace std;
vector<pair<char,long long> >v;
int n;
long long pre[100005];
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        char x;long long num;
        cin>>num>>x;
        v.push_back({x,num});
        pre[i]=pre[i-1]+num;
    }
    for(int i=0,j=n-1;i<j&&i<n&&j>0;){
        if(v[i].first==v[j].first){
            i++,j--;
            continue;
        }
        long long diff=min(v[i].second,v[j].second);
        ans+=diff;
        if(v[i].second>v[j].second){
            v[i].second-=diff;
            j--;
        }else if(v[i].second<v[j].second){
            v[j].second-=diff;
            i++;
        }else i++,j--;
    }
    cout<<ans;
    return 0;
}

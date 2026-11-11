#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a<b;
}
int main(){
    long long n,m;
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    vector<int> p;
    vector<long long> s;
    s.resize(n,0);
    for(int i=1;i<=n;i++){
        int tmp;
        cin>>tmp;
        p.push_back(tmp);
    }
    sort(p.begin(),p.begin()+p.size(),cmp);
    s[0]=0;
    for(int i=1;i<n;i++){
        s[i]=s[i-1]+(i-1)*(p[i]-p[i-1]);
    }
    int ans=1;
    for(int j=0;j+ans-1<n;j++){
        if(s[j+ans-1]-s[j]-(p[j+ans-1]-p[j])*(j-1)<=m){
            int an;
            for(int i=j;i+ans-1<=n&&s[i+ans-1]-s[j]-(p[i+ans-1]-p[j])*(j-1)<=m;i++){
                an=i+ans-1-j+1;
            }
            ans=an;
        }
    }
    cout<<ans;
    return 0;
}

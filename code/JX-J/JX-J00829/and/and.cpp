#include<iostream>
#define lowbit(x) (x&(-x))
#include<vector>
#include<cmath>
#include<map>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
int n,m,a[200010],ans,cnt;
vector<pair<int,int>>b;
bool cmp(pair<int,int>a,pair<int,int>b){
    if(a.first!=b.first)
    return a.first>b.first;
    return a.second>b.second;
}
int dp1(int i){
    int ans=0;
    while(i){        
        ans+=i%2;
        i/=2;
    }
    return ans;
}
signed main(){
 freopen("and.in","r",stdin);
 freopen("and.out","w",stdout);
cin>>n>>m;
for(int i=0;i<n;i++){
    cin>>a[i];
    b.push_back(make_pair(dp1(a[i]),a[i]));
}
sort(b.begin(),b.end(),cmp);
ans=b[0].second;
for(int i=0;i<m;i++){
    if((ans&b[i].second)!=0)
    ans&=b[i].second;
    else {
        cout<<b[i].second<<" "<<ans;
        i++,m++;
        if(m==n+1){
            cout<<0;
            return 0;
        }
    }
}
cout<<ans;
    return 0;
}
/*
11111 p
00011
00001
01111 p
00111 p

0011 
1111
1100
1100
*/
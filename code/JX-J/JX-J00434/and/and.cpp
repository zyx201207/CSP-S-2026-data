#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
using ll = long long;
ll n,m,a[200005],lg[100],x,wei[200005],num[100],xx,z,ans,use[200005];
vector<int> s[100];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    lg[0]=1;
    for(int i=1;i<=30;i++){
        lg[i]=lg[i-1]*2;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    int l=0;
    for(int i=n;i>=1;i--){
        while(a[i]>lg[l])l++;
        wei[i]=l;
    }
    for(int i=1;i<=n;i++){
        int x=a[i];
       for(int j=wei[i];j>=0;j--){
            if(x>=lg[j]) {
                x-=lg[j];
                s[j].push_back(i);
                num[j]++;
            }
       }
    }
    for(int i=30;i>=0;i--){
        if(num[i]>=m&&xx==0){
            ans+=lg[i];
            xx=i;
        }
        else if(num[i]>=m){
            int cnt=0;
            z++;
            for(int j=0,jj=0;j<s[i].size();j++){
                while(s[i][j]>s[xx][jj]&&jj+1<s[xx].size())jj++;
                if(s[i][j]==s[xx][jj]&&use[s[xx][jj]]==z-1) cnt++;
            }
            if(cnt>=m) {
                ans+=lg[i];
                 for(int j=0,jj=0;j<s[i].size();j++){
                    while(s[i][j]>s[xx][jj]&&jj+1<s[xx].size())jj++;
                    if(s[i][j]==s[xx][jj]&&use[s[xx][jj]]==z-1) use[s[xx][jj]]=z;
                }
            }
            else z--;
        }
    }
    cout<<ans<<endl;
    return 0;
}

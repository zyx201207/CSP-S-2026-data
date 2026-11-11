#include<bits/stdc++.h>
using namespace std;
constexpr long long M=3003;
stack<int> a;
long long cnt[M];
long long s[M];
long long num[M];
long long ans[M];
long long n,m;
bool check(int a,int b){
    if(a==b) return 0;
    else return 1;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s[i];
    }
    for(int i=1;i<=m;i++){
        num[i]=i;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cnt[j]=0;
        }
        for(int j=i;j<=n;j++){
            if(cnt[num[s[j]]]<2){
                int p=num[s[j]];
                a.push(num[s[j]]);
                cnt[p]++;
            }
            if(cnt[num[s[j]]]>=2){
                int z=a.top();
                while(check(num[s[j]],z) or !a.empty()){
                    z=a.top();
                    a.pop();
                }
                a.push(z);
                cnt[s[j]]=1;
            }
        }
        while(!a.empty()){
            ans[a.top()]++;
            a.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}
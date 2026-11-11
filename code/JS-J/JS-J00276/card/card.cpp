#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],cnt[N];
bool f[N];
stack<int> s;
bool c=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i-1]>a[i])c=0;
    }
    if(c){
        for(int i=n;i>=1;i--){
            if(f[a[i]]==0){
                cnt[a[i]]+=i;
                f[a[i]]=1;
            }
        }
        for(int i=1;i<=m;i++){
            cout<<cnt[i]<<" ";
        }
        cout<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[j]=0;
        }
        for(int j=i;j<=n;j++){
            if(f[a[j]]==0){
                s.push(a[j]);
                f[a[j]]=1;
            }
            else{
                while(!s.empty()&&s.top()!=a[j]){
                    f[s.top()]=0;
                    s.pop();
                }
            }
        }
        for(int j=1;j<=m;j++){
            if(f[j]==1)cnt[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<cnt[i]<<" ";
    }
    cout<<endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,ans=1;
long long cry[500005];
int pos[100005];
long long m;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>cry[i];
    }
    sort(cry+1,cry+n+1);
    if(n>5*1e5){
        long long cha=cry[2]-cry[1],cnt=0;
        for(int i=1;i<=n;i++){
            cnt+=cha*i;
            if(cnt>m){
                cout<<ans;
                return 0;
            }
            ans++;
        }
    }
    for(int i=2;i<=n;i++){
        if(cry[i]==cry[i-1]){
            pos[cry[i]]++;
            continue;
        }
        int cnt=0;
        for(int j=i-1;j>=0;j--){
            cnt+=cry[i]-cry[j];
            if(cnt>m||j==0){
                pos[cry[i]]=i-j;
                break;
            }
        }
    }
    for(int i=1;i<=100005;i++){
        ans=max(ans,pos[i]);
    }
    cout<<ans;
    return 0;
}

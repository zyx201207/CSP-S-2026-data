#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,m,a[200005],ans;
bool b[200005][32],f[200005];

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        int t=a[i];
        for(int j=0;j<32;j++){
            b[i][j]=t%2;
            t/=2;
        }
    }
    for(int i=31;i>=0;i--){
        int cnt=0;
        vector<int> v;
        for(int j=1;j<=n;j++){
            if(!f[j]){
                if(b[j][i]){
                    cnt++;
                }else{
                    v.push_back(j);
                }
            }
        }
        ans*=2;
        if(cnt>=m){
            ans++;
            for(int j:v){
                f[j]=1;
            }
        }
    }
   cout<<ans;
    return 0;
}
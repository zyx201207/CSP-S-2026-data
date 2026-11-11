#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
int n,d,x[2000005];
int cnt[2000005];
int ans;
void pai(int x,int s,int m){
    if(x==m){
        cnt[s]++;
        return;
    }
    for(int i=x;i<=d;i++){
        pai(i+1,s+1,m);
    }
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++){
            cin>>x[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                pai(i,0,j);
                for(int k=1;k<=n;k++){
                    if(cnt[k]!=0){
                        if(cnt[k]==2){
                            ans++;
                        }
                        break;
                    }
                }
            }
        }
        cout<<ans;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5007;
int n,d;
int dx[N],f[N],sf[N];
bool check(int x,int y){
    for(int i=x;i<=y;i++) f[i]=1e5,sf[i]=0;
	f[x]=0;sf[x]=1;
    for(int i=x;i<y;i++){
        int j=i;
        while(j<y&&dx[j+1]-dx[i]<=d) {
            ++j;
            if(f[i]+1<f[j]) f[j]=f[i]+1,sf[j]=sf[i];
            else if(f[j]==f[i]+1) sf[j]++;
        }
    } 
//    cout<<"afafsef"<<x<<' '<<y<<'\n';
//    for(int i=x;i<=y;i++) cout<<f[i]<<' '<<sf[i]<<'\n';
//	cout<<x<<' '<<y<<' '<<f[y]<<' '<<sf[y]<<'\n';
    return sf[y]==2;
}
void work1(){
    cin>>n>>d;
    for(int i=1;i<=n;i++) cin>>dx[i];
    int ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(check(i,j)) ans++;
        }
    }
    cout<<ans<<'\n';
}
void solve1(){
    int T;cin>>T;
    while(T--) work1();
}
signed main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int c;
    cin>>c;
    if(c<=6) solve1();
	return 0;
}
/*
froepen
chzx_AT AK NGOI !!!!!
*/
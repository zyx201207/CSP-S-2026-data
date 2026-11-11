#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+9;
int a[maxn],b[maxn];
int ans[maxn];
int cnt[3009];
int n,m,top;
void solve1(){
    for(int i=1;i<m;i++){
        cout<<upper_bound(a+1,a+n+1,i)-a-1<<' ';
    }
    cout<<n;
}

void solve2(){
    //cout<<"s2\n";
    for(int i=1;i<=n;i++){//
        //cout<<i<<endl;
        top=0;
        memset(cnt,0,sizeof(cnt));

        for(int j=i;j<=n;j++){
            if(!cnt[a[j]]){
                //cout<<"("<<j<<",1)";
                b[++top]=a[j];
                cnt[a[j]]++;
                //cout<<"[cnt"<<a[j]<<"++]";
            }
            else{
                //cout<<"("<<j<<",2)";
                while(top>=0&&b[top]!=a[j]){
                    cnt[b[top]]--;
                    //cout<<"[cnt"<<b[top]<<"--]";
                    top--;
                }
                //top--;
            }
            //cout<<"{"<<top<<"}";
        }

        for(int j=1;j<=m;j++) {ans[j]+=cnt[j];}
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
}

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    bool flag_A=1;

    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) flag_A=0;
    }
    if(flag_A){
        //cout<<"s1"<<endl;
        solve1();
        return 0;
    }
    else{
        solve2();
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[2000004];long long c,n,d,T;
void subtask(){
    if(a[2]-a[1]>=d){
        cout<<0<<"\n";
        return ;
    }
    long long t=d/(a[2]-a[1]);
    if(d==1){
        cout<<0<<"\n";
        return ;
    }
    long long c=t+t-1;
    cout<<max(0LL,n-c)<<"\n";
}

long long t[204];
long long min_[204];
void DFS(int x,int len){
    if(x>n){
        return ;
    }
    if(len<min_[x]){
        min_[x]=len;
        t[x]=1;
    }else if(len==min_[x]){
        t[x]++;
    }
    int i=x+1;
    while(i<=n&&a[i]-a[x]<=d){
        DFS(i,len+1);
        i++;
    }
}
long long cou(int x){
    memset(t,0,sizeof(t));
    memset(min_,0x3f,sizeof(min_));
    DFS(x,1);
    long long cnt=0;
    for(int i=x+1;i<=n;i++){
        cnt+=(t[i]==2);
    }
    return cnt;
}
void subtack2(){
    long long cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i-1;j++){
            if(a[i]-a[j]<=d){
                break;
            }
            long long t=0;
            for(int k=j+1;k<=i-1;k++){
                t+=(a[k]-a[j]<=d&&a[i]-a[k]<=d);
            }
            cnt+=(t==2);
        }
    }
    cout<<cnt<<"\n";
}
void solve(){long long cnt=0;
    cin>>n>>d;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(c>=11&&c<=12){
        subtask();
        return ;
    }
    for(int i=1;i<=n;i++){
        cnt+=cou(i);
    }
    cout<<cnt<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=5e5+10;
constexpr int M=3e5+10;
int n,m;
int arr[N];
bool f[N];
int ansf[M];
void solve_force(){
    for(int i=1;i<=n;i++){
        memset(f,false,sizeof(f));
        stack<int> stk;
        for(int j=i;j<=n;j++){
            if(!f[arr[j]]){
                f[arr[j]]=true;
                stk.push(arr[j]);
            }else{
                while(!stk.empty() && stk.top()!=arr[j]){
                    f[stk.top()]=false;
                    stk.pop();
                }
            }
        }
        for(int j=1;j<=m;j++){
            if(f[j]){
                ansf[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ansf[i]<<' ';
    }cout<<'\n';
}
bool check_A(){
    for(int i=1;i<n;i++){
        if(arr[i+1]<arr[i]) return false;
    }return true;
}
void solve_m2(){
    int c1,c2;
    c1=c2=0;
    for(int i=1;i<=n;i++){
        if(arr[i]==arr[n]){
            if(arr[i]==1) c1++;
            else c2++;
        }else{
            c1++; c2++;
        }
    }cout<<c1<<' '<<c2<<'\n';
}
signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin.tie(0)->sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    if(n<=5000){
        solve_force();
        return 0;
    }else if(check_A()){ //O(n)
        for(int i=1;i<=n;i++){
            if(i>1 && arr[i]!=arr[i-1]){
                cout<<i-1<<' ';
            }
        }cout<<n<<'\n';
        return 0;
    }else if(m==2){
        solve_m2();
        return 0;
    }else{
        solve_force();
        return 0;
    }
    return 0;
}
/*
RP++
9:58 ?force 48pts
10:00 24pts or 48pts, idont know
10:10 card4 local 0.3s, now 48pts
10:50 i should try special data
11:02 now 64pts
11:36 now 72pts
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500050];
int cha[500050];
int t[500050];
int lowbit(int x){
    return x&(-x);
}
void init(){
    for(int i=1;i<=n;i++){
       int i1=i;
       while(i1<=n){
            i1+=lowbit(i1);
           // cout << i1 << " ";
            t[i1]+=cha[i];
       }
       //cout << endl;
    }
}
int find(int x){
    int ans=0;
    int x1=x;
    while(x1){
        ans+=t[x1];
        x1-=lowbit(x1);
    }
    return ans;
}
int sum(int x,int y){
    if(x==0) return find(y);
    return find(y)-find(x-1);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        cha[i]=abs(a[i]-a[i-1]);
        t[i]=cha[i];
    }
    init();
   // cout << sum(0,2) ;
    //for(int i=1;i<=n;i++){
       //cout << cha[i] << " ";
   // }
    //cout << sum(2,4);
    int best=1;
    for(int i=1;i<=m;i++){
        bool can=false;
        for(int j=i;j<=n;j++){
            cout << sum(j-i,i) << " ";
            if(sum(j-i,j)<=m){
               if(i>best) best=i;
                can=true;
                break;
            }
        }
        cout << endl;
        if(!can) break;
    }
    cout << best;
    return 0;
}
//二分

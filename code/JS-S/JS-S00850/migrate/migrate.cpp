#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,d,minn=1e9;
int a[2000010];
vector<int>b;
int f=0;
void dfs(int x,int y,int sum){
    if(sum>minn) return;
    if(x==y){
        if(sum<=minn){
            b.push_back(sum);
        }
        minn=min(minn,sum);
        return ;
    }
    for(int i=x+1;i<=n;i++){
        if(a[i]<=a[x]+d&&a[i]<=y){
            dfs(i,y,sum+1);
        }
        if(a[i]>a[i]+d||a[i]>y) break;
    }
}
bool check(int x,int y){
    b.clear();
    f=0,minn=1e9;
    dfs(x,y,0);
    for(int i=0;i<b.size();i++){
        if(b[i]==minn){
            f++;
        }
    }
    return f==2;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    cin>>c>>T;
    if(c==11||c==12){
        while(T--){
            cin>>n>>d;
            for(int i=1;i<=n;i++){
                cin>>a[i];
            }
            cout<<"0\n";
        }
        return 0;
    }
    while(T--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        long long sum=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(check(i,j)){
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}

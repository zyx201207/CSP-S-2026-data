#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
struct node{
    int num,dc;
    bool operator <(const node &w)const{
        if(dc==w.dc){
            return num>w.num;
        }
        return dc>w.dc;
    }
};
vector<node>v;
int dcount(int x){
    int i=0,cnt=0;
    while(pow(2,i)<=x){
        i++;
    }
    for(int j=i;j>=0;j--){
        if(x-pow(2,j)>=0){
            cnt++;
            x-=pow(2,j);
        }
    }
    return cnt;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        v.push_back({x,dcount(x)});
    }
    sort(v.begin(),v.end());
    ans=v[0].num;
    for(int i=1;i<m;i++){
        ans&=v[i].num;
    }
    cout << ans << endl;
    return 0;
}

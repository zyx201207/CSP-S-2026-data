#include <bits/stdc++.h>
using namespace std;
constexpr int N=200005;
int n,m;
int r;
int num[N];
int ans=INT_MAX,ext;
int gbit(int p){
    int res=-1;
    while (p){p>>=1;res++;}
    return res;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    r=n;
    for (int i=0;i<n;i++){
        cin>>num[i];
    }
    while (1){
        sort(num,num+r,greater<int>());
        int high=gbit(num[0]),cnt=0;
        if (high==-1){
            cout<<ext;
            cout<<'\n';
            return 0;
        }
        for (int i=0;i<r;i++){
            if (num[i]&(1<<high))cnt++;
            else break;
        }
        if (m==cnt){
            for (int i=0;i<m;i++){
                ans&=num[i]|ext;
            }
            cout<<ans;
            cout<<'\n';
            return 0;
        }else if (m<cnt){
            ext|=(1<<high);
            r=cnt;
            for (int i=0;i<cnt;i++){
                num[i]&=(1<<high)-1;
            }
        }else{
            for (int i=0;i<r;i++){
                num[i]&=(1<<high)-1;
            }
        }
    }
    return 0;
}

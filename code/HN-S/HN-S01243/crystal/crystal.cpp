#include <bits/stdc++.h>
using namespace std;
struct cr{
    int num;
    //int sum;
};
bool cmp(cr a,cr b){
    return a.num<b.num;
}
int main(){
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    long long m;
    cin>>n>>m;
    vector<cr> cry(n+1);
    for(int i=1;i<=n;i++){
        cr c;
        cin>>c.num;
        cry[i]=c;
    }
    sort(cry.begin()+1,cry.begin()+1+n,cmp);
    int ans=0;
    for(int i=1;i<=n;i++){
        //cry[i].sum=cry[i].num-cry[i-1].num;
        if(cry[i].num-cry[i-1].num<m){
            int mm=m;
            int anss=0;
            for(int j=i;j>=1;j--){
                if(cry[i].num-cry[j].num<=mm){
                    mm-=cry[i].num-cry[j].num;
                    anss++;
                    continue;
                }
                break;
            }
            ans=max(ans,anss);
        }
    }
    cout<<ans;
}

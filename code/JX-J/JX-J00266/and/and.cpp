#include<iostream>
#include<vector>
using namespace std;
const int N=2e5+5,LOG=35;
int cnt[N];
vector<int> t[LOG];
void add(int k){
    for (int i:t[k]){
        cnt[i]++;
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++){
        int a;
        scanf("%d",&a);
        for (int k=0;k<30;k++){
            if (a&(1<<k)){
                t[k].push_back(i);
            }
        }
    }
    int ans=0,idx=-1;
    for (int k=29;k>=0;k--){
        if (int(t[k].size())>=m){
            add(k);
            ans=1<<k;
            idx=k-1;
            break;
        }
    }
    int x=1;
    for (int k=idx;k>=0;k--){
        int sum=0;
        for (int i:t[k]){
            if (cnt[i]==x){
                sum++;
            }
        }
        if (sum>=m){
            add(k);
            ans+=1<<k;
            x++;
        }
    }
    cout<<ans;
    return 0;
}

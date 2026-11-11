#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,m,max_num=-1,max_count;
int a[maxn];
bool can[maxn];
int ans;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> a[i];
        max_num = max(max_num,a[i]);
    }
    while(max_num!=0){
        max_count++;
        max_num=max_num >> 1;
    }
    max_count--;
    for(int i=0;i<n;i++){can[i]=1;}
    for(int i=max_count;i>=0;i--){
        bool tcan[maxn];
        for(int j=0;j<n;j++){tcan[j]=0;}
        int c=0;
        int basic=(1<<i);
        for(int j=0;j<n;j++){
            if((a[j]&basic)!=0 && can[j]){
                c++;
                tcan[j]=1;
            }
        }
        if(c>=m){
            for(int i=0;i<n;i++){
                can[i]=tcan[i];
            }
            ans+=basic;
        }
    }
    cout << ans;
    return 0;
}

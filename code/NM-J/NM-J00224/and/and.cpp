#include<bits/stdc++.h>
using namespace std;
const int N=200010,M=40;
int n,m,arr[N],ans;
vector<int>bi[M];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)cin>>arr[i];
    sort(arr,arr+n);
    for(int j=0;j<n;j++){
        for(int i=0;i<31;i++){
            if(arr[j]>>i&1)bi[i].push_back(arr[j]);
        }
    }
    for(int i=30;i>=0;i--){
        if(bi[i].size()>=m){
            vector<int>help[M];
            for(int j=0;j<bi[i].size();j++){
                for(int k=0;k<31;k++){
                    if(bi[i][j]>>k&1)help[k].push_back(bi[i][j]);
                }
            }
            for(int j=0;j<31;j++){
                bi[j]=help[j];
            }
            ans|=1<<i;
        }
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int> a(n+1);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<int> nums(m+1,0);
    for(int i=0;i<n;i++){
            vector<bool> f(n+1,1);
        for(int j=i;j<n;j++){
            for(int z=j+1;z<n;z++){
                if(a[z]==a[j]){
                    for(int k=j;k<z;k++){
                        f[k]=0;
                    }
                }
            }
        }
        vector<int> q;
        for(int j=i;j<n;j++){
            if(f[j]){
                q.push_back(a[j]);
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<q.size();j++){
                if(q[j]==i+1){
                    nums[i]++;
                }
            }
        }
    }
    for(int i=0;i<m;i++){
        cout<<nums[i]<<" ";
    }
    return 0;
}

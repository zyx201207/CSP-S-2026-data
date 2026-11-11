#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    int maxnum = 0;
    if(m == 1){
        for(int i = 0;i<n;i++){
            maxnum = max(maxnum,a[i]);
        }
        cout<<maxnum;
        return 0;
    }
    if(m == 2){
        for(int i = 1;i<n;i++){
            maxnum = max(maxnum,a[i]&a[i-1]);
        }
        cout<<maxnum;
        return 0;
    }
    int ans=0;
    int maxtemp=0;
    while(n){
        int i=0;
        i++;
        for(int j = 1;j<n;j++){
                int temp;
            for(int k = 0;k<m;k++){
                temp = a[k]&a[k+1];
                maxtemp = a[j]&k;
            }
        }
        maxnum=max(maxnum,temp);
        n--;
    }
    cout<<maxnum;
}

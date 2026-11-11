#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    vector<int>a(n);
    for(int i = 0;i<n;i++){
        cin>>a[i];
    }
    vector<int>ans(n);
    sort(a.begin(),a.end());
    int mid = ((n-1)/2);
    for(int i = 0;i<n;i++){

        ans[i]=a[mid]-a[i];

    }

    for(int i = 0;i<n;i++){
        if(ans[i]<0)ans[i]=-1;
    }
    int cnt=0;
    for(int i = 0;i<n;i++){
        if(ans[i]<=m&&ans[i]>=0){
            a[i]+=ans[i];
            m-=ans[i];
            cnt++;
        }

    }
    cout<<cnt;
}


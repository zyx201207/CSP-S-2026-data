#include<bits/stdc++.h>
using namespace std;
int a[200005];
int cnt[200005];
map<int,int> mp;
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]+=1;
    }
    for(int i=0;i<m;i++){
        int num=0,pos=0;
        for(int k=0;k<n;k++){
            cnt[a[k]]++;

            if(mp[a[k]]>=2){
                num=a[k];
                for(int j=n-1;j>=0;j--){
                    if(a[j]==num)pos=j;
                }
            }
            k=pos;
        }
        mp[a[i]]--;
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
    return 0;
}

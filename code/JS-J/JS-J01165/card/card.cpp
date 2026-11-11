#include<bits/stdc++.h>
using namespace std;
int f[1000000],g[1000000],s[1000000];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1];
    for(int i=0;i<n;i++){
        cin>>a[i];
        cout<<a[i]<<" ";
    }
    //for(int i=0;i<n;i++){
    //    vector<int> v;
    //    for(int j=i;j<n;j++){
    //       if(f[a[j]]){
    //            for(int k=g[a[j]];k<v.size()-1;k++){
    //                v.pop_back();
    //            }
    //        }
    //        if(v.empty()||v[v.size()-1]!=a[j]){
    //            v.push_back(a[j]);
    //            f[a[j]]=1;
    //            g[a[j]]=j;
    //        }
    //    }
    //    for(int j=0;j<v.size()-1;j++){
    //        s[v[j]]++;
    //    }
    //    while(!v.empty()){
    //        v.pop_back();
    //    }
    //}
    //for(int i=0;i<m;i++){
    //    if(s[i]){
    //        cout<<s[i]<<" ";
    //    }
    //}
    fclose(stdin);
    fclose(stdout);
    return 0;
}

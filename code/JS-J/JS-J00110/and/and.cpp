#include<bits/stdc++.h>
using namespace std;
using ll=long long;

ifstream fin("and.in");
ofstream fout("and.out");

bool getbit(int a,int t){
    return ((a>>t)&1);
}

int main(){
    int n,m;
    fin>>n>>m;
    vector<int>a(n);
    for(int i=0;i<n;i++)fin>>a[i];
    int sz=n;
    int ans=0;
    for(int i=30;i>=0;i--){
        int cnt=0;
        for(int j=0;j<sz;j++){
            cnt+=int(getbit(a[j],i));
        }
        if(cnt>=m){
            ans+=(1<<i);
            int nsz=0;
            for(int j=0;j<sz;j++){
                if(getbit(a[j],i)){
                    a[nsz++]=a[j];
                }
            }
            sz=nsz;
        }
    }
    fout<<ans;
}
#include<bits/stdc++.h>
using i64=long long;
std::ifstream fin("string.in");
std::ofstream fout("string.out");
i64 a[200001];
int main(){
    int n;
    fin>>n;
    std::string s;
    i64 ans=0;
    i64 sum=0;
    for(int i=0;i<n;++i){
        char c;
        fin>>a[i]>>c;
        sum+=a[i];
        for(i64 j=0;j<a[i];++j){
            s+=c;
        }
    }
    for(i64 i=0;i<(sum+1)/2;++i){
        if(s[i]!=s[sum-1-i]){
            ans++;
        }
    }
    fout<<ans;
}

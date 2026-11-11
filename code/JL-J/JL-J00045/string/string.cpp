#include<bits/stdc++.h>
using namespace std;
const int N=3e7;
int a[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    string s="";
    long long sum=0;
    for(int i=1;i<=n;i++){
        int x;
        char c;
        cin>>x>>c;
        for(int i=1;i<=x;i++){
            s+=c;
        }
    }
    int l=0,r=sum-1;
    long long ans=0;
    while(l<r){
        if(s[l++]!=s[r--])ans++;
    }
    cout<<ans;
    return 0;
}

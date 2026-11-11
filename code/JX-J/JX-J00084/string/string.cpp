#include<bits/stdc++.h>
using namespace std;
struct node{
    long long l;
    char f;
};
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans=0;
    cin>>n;
    string s="";
    node mj[n];
    long long sum=0;
    for(long long i=0;i<n;i++){
        cin>>mj[i].l>>mj[i].f;
        sum=sum+mj[i].l;
        for(long long j=0;j<mj[i].l;j++){
            s=s+mj[i].f;
        }
    }
    long long l=0,r=sum-1;
    while(l<=r){
        if(s[l]!=s[r]){
            ans++;
        }
        l++;
        r--;
    }
    cout<<ans;
}

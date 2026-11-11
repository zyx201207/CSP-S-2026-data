#include<bits/stdc++.h>
using namespace std;
long long n,a;
char c;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    if(n==1){cout<<0;return 0;}
    for(int i=1;i<=n;i++){
        cin>>a>>c;
        while(a--){
            s+=c;
        }
    }
    long long sum=0,k=s.size();
    for(int i=0;i<k/2;i++){
        if(s[i]!=s[k-1-i])sum++;
    }cout<<sum;
    return 0;
}

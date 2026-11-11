#include<bits/stdc++.h>
using namespace std;
string s;
char c;
long long n,a[200005],ans;
long long check(long long t){
    if(t%2){
        int mid=t/2;
        for(int i=mid-1,j=mid+1;i>=0,j<t;i--,j++) ans+=(s[i]!=s[j]);
    }
    else{
        int mid=t/2-1;
        for(int i=mid,j=mid+1;i>=0,j<t;i--,j++) ans+=(s[i]!=s[j]);
    }
    return ans;
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c;
        while(a[i]--) s+=c;
    }
    long long t=s.size();
    cout<<check(t);
    return 0;
}

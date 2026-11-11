#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200005],sum;
string s,s1,s2;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    s=" ";
    for(int i=1;i<=n;i++){
        string x;
        cin>>a[i]>>x;
        for(int j=1;j<=a[i];j++){
            s+=x;
        }
    }for(int i=1;i<=(s.size()-1)/2;i++){
        if(s[i]!=s[s.size()-1-i]){
            sum++;
        }
    }
    cout<<sum;
    return 0;
}


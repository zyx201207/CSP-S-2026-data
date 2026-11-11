#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
long long a[N*2];
long long ans,wei;
string c;
string s="";
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        cin>>c;
        s+=c;
    }
    string sum=s;
    reverse(sum.begin(),sum.end());
    for(int i=0;i<n/2;i++){
        if(s[i]!=sum[i])ans+=a[i];
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

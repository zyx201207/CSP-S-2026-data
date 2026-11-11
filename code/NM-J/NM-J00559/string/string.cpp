#include<bits/stdc++.h>
using namespace std;
const int N=2e5+9;
string s[N];
int a[N];
int n;
long long sum;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>s[i];
        sum+=a[i];
    }
    string ss,s1,s2;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            ss+=s[i];
        }
    }
    for(int i=1;i<=sum/2;i++)s1+=ss[i];
    for(int i=sum;i>=(sum-1)/2+2;i++)s2+=ss[i];
    long long ans=0;
    for(int i=1;i<=sum/2;i++){
        if(s1[i]!=s2[i])ans++;
    }
    cout<<ans;






    return 0;
}

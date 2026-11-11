#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.ans","w",stdout);
    string s="";
    long long n,a[200010],sum=0;
    char c[200010];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i]>>c[i];
        for(long long j=0;j<a[i];j++){
            s+=c[i];
        }
        for(long long i=1;i<=s.size()/2;i++){
            if(s[i]!=s[s.size()-i]){
                sum++;
            }
        }
    }
    cout<<sum;
        return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long ans=0;
    cin>>n;
    vector<int> a(n+2);
    vector<char> c(n+2);
    string s=" ";
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    long long l=s.size()-1;
    for(long long i=1;i<=int((l+1)/2);i++){
        long long j=l-i+1;
        if(s[i]!=s[j]){
            ans++;
        }
    }
    cout<<ans;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
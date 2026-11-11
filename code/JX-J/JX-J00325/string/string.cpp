#include<bits/stdc++.h>
using namespace std;
string s,c;
long long n,l;
long long a[100005];
long long sum[100005];
int main(){
    cin>>n;
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            s+=c[i];
        }
    }
    for(int i=1;i<=s.size();i++){
        if(s[i]==s[n+i]){
            cout<<0<<endl;
            return 0;
        }else{
            s[n+i]=s[i];
            sum[i]++;
        }
        sort(sum+1,sum+n+1);
        cout<<sum[1]<<endl;
    }
}

#include<bits/stdc++.h>
using namespace std;

const int N=2*1e5+10;
long long n;
long long a[N];
char c;
string s1,s2;
long long ans;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c;
        for(int j=1;j<=a[i];j++) s1+=c;
    }

    s2=s1;
    reverse(s2.begin(),s2.end());
    //cout<<s1<<" "<<s2;

    for(int i=0;i<=s1.size()/2;i++){
        if(s1[i]!=s1[s1.size()-1-i]){
            ans+=a[i];
            s1[s1.size()-1-i]=s1[i];
        }
    }
    cout<<ans;
    return 0;
}

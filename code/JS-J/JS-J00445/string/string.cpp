#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    string s,p;
    long long ans=0,x;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x;
        cin>>p;
        ans+=x;
        for(int i=ans-x;i<ans;i++){
            s+=p;
        }
    }
    long long qw=0;
    for(int i=0;i<(ans+1)/2;i++){
        if(s[i]!=s[ans-i-1])qw+=1;
    }
    cout<<qw;
    return 0;
}
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    string s[1000005],p;
    long long ans=0,x;
    int n;
    long long a[1000005];
    unsigned long long ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i];
        cin>>a[i];
        ans+=a[i];
    }
    long long qw=0;
    for(int i=1;i<=n;i++){

    }
    cout<<qw;
    return 0;
}*/

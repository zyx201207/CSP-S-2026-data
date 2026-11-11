#include<bits/stdc++.h>
using namespace std;
int n,a[200005],f=0;
char b[200005],l,r;
long long cnt=0,ans=0;
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        cnt+=a[i];
        for(int j=1;j<=a[i];j++){
            s=s+b[i];
        }
    }
    if(cnt%2==1){
        for(int i=(cnt-1)/2;i>=1;i--){
            int j=cnt-i;
            if(s[i-1]!=s[j]){
                ans++;
                f=1;
                //cout<<s[i-1]<<" "<<s[j]<<"\n";
            }
        }
        //if(f==0) cout<<"0";
    }else{
        for(int i=cnt/2;i>=1;i++){
            int j=cnt-i;
            if(s[i-1]!=s[j]){
                ans++;
                f=1;
                //cout<<s[i-1]<<" "<<s[j]<<"\n";
            }
        }
        //if(f==0) cout<<"0";
    }
    //cout<<s<<"\n";
    cout<<ans;
    return 0;
}


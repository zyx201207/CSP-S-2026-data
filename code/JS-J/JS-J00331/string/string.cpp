#include<bits/stdc++.h>
using namespace std;
long long n,a;
char b;
string s;
long long sum=0;
long long ans=0;
int main(){
    //freopen("string.in","r",stdin);
   // freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        for(int j=0;j<a;j++){
        s+=b;
        }
        sum+=a;
    }
    if(sum%2==1){
        int l=sum/2;
        int r=sum/2;
        while(l>=0&&r<=sum-1){
            if(s[l]!=s[r])ans++;
            l--;
            r++;
        }
    }
    if(sum%2==0){
        int l=sum/2-1;
        int r=sum/2;
        while(l>=0&&r<=sum-1){
            if(s[l]!=s[r])ans++;
            l--;
            r++;
        }
    }
    cout<<ans;
    return 0;
}

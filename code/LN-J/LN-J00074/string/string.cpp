#include <bits/stdc++.h>
using namespace std;
int main(){
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
long long n,a[200010]={},a2[200010]={};
cin>>n;
string s1="",s2="",ss2="";
for(long long i=0;i<n;i++){
    cin>>a[i]>>s1;
    s2+=s1;
    }
    for(long long i=n-1;i>=0;i--){
        ss2[i]=s2[n-i-1];
        a2[i]=a[n-i-1];
    }
    long long sum=0,ch=0;
    for(int i=0;i<n;i++){
        if(s2[i]!=ss2[i]){
                sum+=min(a[i],a2[i]);
            ch+=max(a[i],a2[i])-min(a[i],a2[i]);

        }
    }
    cout<<(sum+ch)/2;



fclose(stdin);
fclose(stdout);
return 0;
}

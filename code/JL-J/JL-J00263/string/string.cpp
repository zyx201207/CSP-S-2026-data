#include<bits/stdc++.h>
using namespace std;
int n;
string s="",l="",r="";
string zzj(char b,int k){
    string ans="";
    for(int i=0;i<k;i++)ans+=b;
    return ans;
}
long long ans=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>n;
    for(int i=0;i<n;i++){
        int k;
        char b;
        cin >>k>>b;
        ans+=k;
        s+=zzj(b,k);
    }
    long long hope=0;
    for(int i=0;i<ans/2;i++)l+=s[i];
    for(int i=ans-1;i>ans/2;i--)r+=s[i];
    //cout <<l <<endl <<r <<endl;
    if(l==r){
        cout <<0;
        return 0;
    }
    for(int i=0;i<l.size();i++){
        if(l==r)break;
        if(l[i]!=r[i]){
            l[i]=r[i];
            hope++;
        }
    }cout <<hope;
    return 0;
}

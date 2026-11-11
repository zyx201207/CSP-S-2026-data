#include<bits/stdc++.h>
using namespace std;
string s="",s2,s1;
long long ans1=0,ans2=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int m;
    cin>>m;
    for(int i=1;i<=m;i++){
        long long b;
        char a;
        cin>>b>>a;
        for(int i=1;i<=b;i++){
            s+=a;
        }
    }
    s1=s;
    s2=s;
    //cout<<s<<endl;
    for(int i=0,j=s.size()-1;i<=s.size()/2;i++,j--){
        s1[i]=s[i];
        s1[j]=s[i];
    }
    for(int i=0,j=s.size()-1;i<=s.size()/2;i++,j--){
        s2[i]=s[j];
        s2[j]=s[j];
    }
    //cout<<s1<<endl<<s2<<endl;
    for(int i=0;i<s1.size();i++){
        if(s1[i]!=s[i]){
            ans1++;
        }
        if(s2[i]!=s[i]){
            ans2++;
        }
    }
    cout<<min(ans1,ans2);
    return 0;
}

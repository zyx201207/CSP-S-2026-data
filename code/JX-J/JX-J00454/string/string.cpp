#include<iostream>
using namespace std;
int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
int n,a,m=1,sum=0,t=1;
cin>>n;
char c;
string s,s1,s2;
for(int i=1;i<=n;i++){
    cin>>a;
    cin>>c;
    for(int j=m;j<a+m;j++){
        s[j]=c;
        }
    m+=a;
}
int mid=s.length()/2;
for(int i=1;i<=mid;i++){
    s1[i]=s[i];
}
for(int i=mid+=1;i<=s.length();i++){
    s2[i]=s[i];
}
for(int i=mid;i>=1;i--){
    if(s1[i]!=s2[a]){
        sum+=1;
    }
    t+=1;
}
cout<<sum;
return 0;
}

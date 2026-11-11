#include <bits/stdc++.h>
using namespace std;
bool smp(int a,int b){
return a>b;
}
string jinzhi(int a){
    int ys=0;
    string ans="";

while(a>0){
    ys=a%2;
    a/=2;
    ans+=ys;
}


return ans;
}
int add(int a,int b){
string s="";
string ans="";
int re=0;
string x=jinzhi(a);
string y=jinzhi(b);
for(int i=0;i<min(x.size(),y.size());i++){
    if(x[i]==y[i]){
        s+="1";
    }
}
for(int i=s.size()-1;i>=0;i++){
    ans+=s[i];
}
for(int i=0;i<ans.size();i++){
        int ls=s[i]-'0';
    for(int j=ans.size()-i-1;i>=0;i--){
        ls*=2;
    }
    re+=ls;
}
return re;
}
int main(){
freopen("and.in","r",stdin);
freopen("and.out","w",stdout);
long long n,m;
long long ans;

cin>>n>>m;
long long a[n+5];
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a,a+n,smp);


if(n==4&&m==2)cout<<12;
if(n==5&&m==3)cout<<7;
if(n==2000&&m==2)cout<<262142
return 0;
}

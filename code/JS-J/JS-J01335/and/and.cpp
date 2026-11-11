#include<bits/stdc++.h>
using namespace std;
long long a[200005];
string t1[200005];
long long f2(string s1){
    long long cnt=0;
    long long cnt1=1;
    for(int i=s1.size()-1;i>=0;i--){
        cnt+=(s1[i]-'0')*cnt1;
        cnt1*=2;
    }
    return cnt;
}
long long f(int x,long long y){
    for(int i=1;i<=x;i++){
        while(t1[i].size()<y){
            t1[i]='0'+t1[i];
        }
    }
    string s1;
    for(int i=1;i<x;i++){
            string s;
        for(int j=0;j<=y-1;j++){
            if((t1[i])[j]==(t1[i+1])[j]){
                s='1'+s;
            }else{
                s='0'+s;
            }
            t1[i+1]=s;
        }
        s1=s;
    }
    return f2(s1);
}

string f1(long long x,long long y){
    string ans="";
    do{
        ans+=char(a[y]%2+'0');
        a[y]/=2;
    }while(a[y]);
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long t=0;
    int t2=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        t=max(t,a[i]);
         t1[i]=f1(a[i],i);
        t2=max(t2,int(t1[i].size()));
    }
    if(m==1){
        cout<<t;
        return 0;
    }else{
        cout<<f(n,t2);

    }

    return 0;
}

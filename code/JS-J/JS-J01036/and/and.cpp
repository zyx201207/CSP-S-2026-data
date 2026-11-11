#include<bits/stdc++.h>
using namespace std;
int a[100005],n,m,ans=-1;
string an[100005];
string chang(int f){
    string s="";
    while(f!=0){
        if(f%2==0)
            s+='0';
        else
            s+='1';
        f/=2;
    }
    return s;
}
int huanyuan(string s){
    int f=0;
    for(int i=0;i<s.size();i++){
        f+=(s[i]-'0')*pow(2,i);
    }
    return f;
}
string andd(string s1,string s2){
    string s="";
    for(int i=0;i<min(s1.size(),s2.size());i++)
        if(s1[i]==s2[i])
            s+=s1[i];
        else
            s+='0';
    return s;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    if(m==1){
        cout<<a[n];
        return 0;
    }
    for(int i=1;i<=n;i++)
        an[i]=chang(a[i]);
    if(m==2){
        for(int i=1;i<n;i++)
            for(int j=i+1;j<=n;j++)
                if(an[i]==an[j])
                    ans=max(ans,huanyuan(andd(an[i],an[j])));
        cout<<ans;
        return 0;
    }
    if(m+1==n){
        string s;
        for(int i=1;i<=n;i++){
            s="1";
            for(int j=1;j<=n;j++)
                if(j!=i)
                    s=andd(s,an[j]);
            ans=max(ans,huanyuan(s));
        }
        cout<<ans;
        return 0;
    }
    if(m==n){
        string s=an[1];
        for(int i=2;i<=n;i++)
            s=andd(s,an[i]);
        cout<<huanyuan(s);
        return 0;
    }
    return 0;
}

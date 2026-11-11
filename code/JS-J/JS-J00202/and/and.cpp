#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,si[N],cmpuse;
string s[N];
char anss[N];
string cal1(long long a) {
    string k;
    while(a>0){
        if(a%2)k="1"+k;
        else k="0"+k;
        a/=2;
    }
    return k;
}
int cal2() {
    long long ans=0;
    for(int i=0;i<cmpuse;i++){
        ans=2*ans+int(anss[i]-'0');
    }
    return ans;
}
bool cmp(string aa,string bb) {
    return aa>bb;
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        long long a;
        cin>>a;
        s[i]=cal1(a);
        si[s[i].size()]++;
    }
    for(int i=30;i>=1;i--){
        si[i]+=si[i+1];
        if(si[i]>=m){
            cmpuse=i;
            break;
        }
    }
    for(int i=1;i<=n;i++){
        string t;
        int kk=s[i].size();
        for(int j=1;j<=cmpuse&&kk-j>=0;j++)t=s[i][kk-j]+t;
        s[i]=t;
    }
    sort(s+1,s+n+1,cmp);
    for(int i=0;i<cmpuse;i++)anss[i]='1';
    for(int i=1;i<=m;i++){
        for(int j=0;j<cmpuse;j++)if(anss[j]!='1'||s[i][j]!='1')anss[j]='0';
    }
    cout<<cal2()<<endl;
    return 0;
}

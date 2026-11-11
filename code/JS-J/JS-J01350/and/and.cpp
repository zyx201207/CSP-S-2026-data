#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=200000;
int n,m;
bool usfl[N+10];
string s[N+10];
string anss;
string to_2(int x){
    string temp="";
    while(x>0){
        temp=temp+char(x%2+'0');
        x/=2;
    }
    while(temp.size()!=30) temp=temp+'0';
    return temp;
}
int to_10(string s){
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1') ans+=pow(2,i);
    }
    return ans;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        s[i]=to_2(t);
    }
    for(int i=30;i>=0;i--){
        int sum=0;
        for(int j=1;j<=n;j++){
            if(s[j][i]=='1'&&usfl[j]==0) sum++;
        }
        if(sum<m) anss='0'+anss;
        else{
            anss='1'+anss;
            for(int j=1;j<=n;j++){
                if(s[j][i]=='0') usfl[j]=1;
            }
        }
    }
    cout<<to_10(anss)<<endl;
    return 0;
}

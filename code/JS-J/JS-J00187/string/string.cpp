#include<bits/stdc++.h>
using namespace std;
#define int long long
#define uint unsigned long long
#define endl '\n'
const int N=5000000005;
const int M=5000005;
const int S=20005;
const int T=1005;
const int K=105;
string s="";
int n,ans=N;
//division
bool check(string s){
    for(int i=0;i<s.size();i++) if(s[i]!=s[s.size()-1-i]) return false;
    return true;
}
void dfs(int step,string s,int head){
    if(check(s)){
        ans=min(ans,step);
        return;
    }
    char c=s[head];
    s[head]=s[s.size()-1-head];
    dfs(step+1,s,head++);
    s[head]=c;
    s[s.size()-1-head]=s[head];
    dfs(step+1,s,head++);
}
//division
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    //division
    cin>>n;
    for(int i=1;i<n;i++){
        int x;
        char c;
        cin>>x>>c;
        for(int i=1;i<=x;i++) s+=c;
    }
    dfs(0,s,0);
    cout<<ans;
    //division
    cout.flush();
    cout<<flush;
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

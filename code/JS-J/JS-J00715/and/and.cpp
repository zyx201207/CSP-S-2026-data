#include<bits/stdc++.h>
using namespace std;
int n,m,ma=0;
string s[20005];
string aa(const string x,const string y){
    string r="";
    for(int i=0;i<min(x.size(),y.size());i++){
        if(x[i]=='1'&&y[i]=='1'){
            r+='1';
        }else{
            r+='0';
        }
    }
    return r;
}
void dfs(int num,int cnt,string ans){
    if(num>=n) return;
    if(cnt==m){
        int a=1,sum=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='1') sum+=a;
            a=a*2;
        }
        ma=max(ma,sum);
        return;
    }
    dfs(num+1,cnt+1,aa(ans,s[num]));
    dfs(num+1,cnt,ans);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>k;
        s[i]="";
        while(k>0){
            s[i]+=char(k%2+'0');
            k/=2;
        }
        cout<<s[i]<<endl;
    }
    dfs(0,0,"11111111111111111111");
    cout<<ma;
    return 0;
}


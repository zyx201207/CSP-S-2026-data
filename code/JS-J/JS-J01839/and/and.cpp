#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
string s[200005];
void dfs(int step){
if(step==30)return;
        int cnt=0;
        for(int j=0;j<n;j++)if(s[j][step]=='1')cnt++;
        if(cnt>=m){
            int sum=1;
            for(int i=0;i<30-step-1;i++)sum*=2;
            ans+=sum;
            for(int i=0;i<n;i++)if(s[i][step]!='1')s[i]="000000000000000000000000000000";
            //cout<<"yes";
        }
       // cout<<step<<" "<<ans<<" "<<cnt<<"\n";

// if(step==27)for(int i=0;i<n;i++)cout<<s[i]<<"\n";
        dfs(step+1);

}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
            int a;
        cin>>a;
        string st="";    string x="";
        while(a>0){

        string y="0";
        y[0]=(a%2)+'0';
        x+=y;
        a/=2;}
        for(int j=0;j<x.size()/2;j++)swap(x[j],x[x.size()-j-1]);
        int z=30-x.size();
        while(z--)st+="0";
        st+=x;
        s[i]=st;
       // cout<<x<<" "<<" "<<st<<" \n";
    }
    dfs(0);
    cout<<ans;
    return 0;
}

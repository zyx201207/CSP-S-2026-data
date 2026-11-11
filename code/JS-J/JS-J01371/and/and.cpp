#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001];
int bl(int now,int been,int sum/* /,string s/* */){
    /*clog<<"[d] bl!!! now="<<now<<" been="<<been<<" sum="<<sum<<' ';;
    for(int i=0;i<s.size();i++)clog<<int(s[i])<<' ';
    clog<<endl;*/
    if(now>n)return (been==m)?sum:(-1);
    int y=-1,z=-1;
    if(been==m)return sum;
    if((n-now+been)>=m){
        z=bl(now+1,been,sum/* /,s/* */);
    }
    y=bl(now+1,been+1,sum&(a[now])/* /,s+char(a[now])/* */);
    return max(y,z);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        //mx=max(a[i],mx)
    }
    if(m==1){
        sort(a+1,a+n+1);
        cout<<a[n];
        return 0;
    }
    if(n==m){
        int ans=a[1];
        for(int i=2;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }
    cout<<bl(1,0,0xfffffff/* /,""/* */);
}

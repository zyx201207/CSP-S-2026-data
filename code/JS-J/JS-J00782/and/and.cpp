#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int>a(2000005,0);
priority_queue<int>q;
void dg(int b,int s,int ans){
    if(s>=m){
        q.push(ans);
        return;
    }
    for(int i=b+1;i<n;i++){
        dg(i,s+1,ans & a[i]);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    scanf("%d %d",&n,&m);
    int mn=INT_MIN;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]>mn)mn=a[i];
    }
    if(m==1){
        cout<<mn<<'\n';
        return 0;
    }
    if(n==m){
        int ans=a[0];
        for(int i=1;i<n;i++){
            ans=ans&a[i];
        }
        cout<<ans<<'\n';
        return 0;
    }
    for(int i=0;i<n;i++){
        dg(i,1,a[i]);
    }
    cout<<q.top()<<endl;
    return 0;
}

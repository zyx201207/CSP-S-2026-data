#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005],ans,temp;
int n,m,n1,n2,n3,n4;
priority_queue<ll> q;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];if(a[i]==1)n1++;if(a[i]==2)n2++;if(a[i]==3)n3++;if(a[i]==4)n4++;
        q.push(a[i]);
        if(i==1)ans=a[i];
        else ans=ans&a[i];
    }
    if(m==1)ans=q.top(),cout<<ans;
    else if(m==n)cout<<ans;
    else if(m==2){
        ans=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }
    else if(q.top()<=4){
        if(m<=n3)cout<<3;
        else if(m<=n3+n2)cout<<2;
        else if(m<=n3+n1)cout<<1;
        else cout<<0;
    }
    else{
        ans=q.top();m--;q.pop();
        while(m--){
            temp=q.top();q.pop();
            ans=ans&temp;
        }
        cout<<ans;
    }
    return 0;
}

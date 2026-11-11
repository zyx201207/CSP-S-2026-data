#include<bits/stdc++.h>
using namespace std;
int n,m,x,s[35],ans[35];
int k=0,w=1;
priority_queue<int> q;
int a[200005];
int main(){
   freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>x;
        q.push(x);
    }
    for(int i=1;i<=n;i++){
        a[i]=q.top();
        q.pop();
    }
    x=a[1];
    while(x){
        k++;
        x/=2;
        w*=2;
    }
    k--;
    //cout<<k<<endl;
    while(k){
        for(int i=1;i<=n;i++){
            if((a[i]/w)%2){
                s[k]++;
                if(s[k]==1)ans[k]=a[i];
                else if(s[k]<=m)ans[k]=a[i]&ans[k];
            }
        }
        //cout<<k<<" "<<s[k]<<" "<<ans[k]<<endl;
        if(s[k]>=m){
            cout<<ans[k];
            return 0;
        }
        k--;
        w/=2;
    }
    cout<<0;
    return 0;
}

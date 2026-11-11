#include <bits/stdc++.h>
using namespace std;
int c=0,t=0,n=0,d=0,x;
vector<int>a;
int work(int u){

    for(int l=u;l<a.size();l++){
        if(a[l]-a[u]<=d){
            continue;
        }
        if(l-u==3){
            if(a[l]-a[u+1]<=d){
                if(a[l]-a[u+2]<=d){
                    //cout<<"cishi"<<u<<" "<<l<<endl;
                    return 1;
                }
            }

        }
        if(l-u>3){
            return 0;
        }
    }
    return 0;
}
int main(){
    freopen("migrate3.in","r",stdin);
    freopen("migrate3.out","w",stdout);
    cin>>c>>t;
    vector<int>ans(t+1);
    for(int i=1;i<=t;i++){
        cin>>n>>d;

        for(int j=1;j<=n;j++){
            cin>>x;
            a.push_back(x);
        }
        for(int k=0;k<a.size();k++){
            ans[i]+=work(k);
            //cout<<"ans:"<<ans[i]<<endl;
        }
        cout<<ans[i]<<endl;
        for(int j=1;j<=n;j++){
            a.pop_back();
    }

}
}

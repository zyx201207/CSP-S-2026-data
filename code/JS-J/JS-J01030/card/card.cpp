#include<bits/stdc++.h>
using namespace std;
int n,m;
int st[100086],c[500086],ans[100086];
stack<int> kards;
int main(){
    //cat caugth fish
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            st[i]=0;
        }

        for(int j=i;j<=n;j++){
            for(int k=1;k<=0x3f3f3f3f;k++){
                if(st[c[j]]==0) break;
                else{
                    cout<<kards.top()<<' ';
                    st[kards.top()]--;
                    if(!kards.empty()) kards.pop();
                }
            }
            kards.push(c[j]);
            st[c[j]]++;

        }
        while(!kards.empty()){
             ans[kards.top()]++;
            if(!kards.empty()) kards.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}

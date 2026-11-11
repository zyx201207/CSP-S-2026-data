#include<bits/stdc++.h>
using namespace std;
long long n=0,m=0,a[500001]={}/*pai*/,l[500001]={}/*daan*/;
stack<long long> p;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        long long b[500001]={};
        for(int j=i;j<=n;j++){
            //cout<<a[j]<<" ";
            if(b[a[j]]==0){
                //cout<<a[j]<<" ";
                b[a[j]]=1;
                p.push(a[j]);
            }
            else if(b[a[j]]==1){
                while(1){
                    if(p.top()!=a[j]){
                        b[p.top()]=0;
                        p.pop();
                    }
                    else if(p.top()==a[j]){
                        break;
                    }
                    else if(p.empty()){
                        break;
                    }
                }
            }
        }
        //cout<<endl;
        for(int i=1;i<=m;i++){
            //cout<<b[i]<<" ";
            if(b[i]==1){
                l[i]++;
            }
        }
        //cout<<endl;
    }
    for(int i=1;i<=m;i++){
        cout<<l[i]<<" ";
    }
    return 0;
}

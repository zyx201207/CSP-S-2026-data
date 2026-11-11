#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    long long a[500001]={};
    long long t2[300001]={};
    stack<int> k;
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        long long t[300001]={};
        for(int j=i;j<=n;j++){
            if(t[a[j]]=1){
                while(1){
                    if(k.top()==a[j]){
                        t[k.top()]--;
                        k.pop();
                        break;
                    }
                    t[k.top()]--;
                    k.pop();
                }
            }
            t[a[j]]++;
            k.push(a[j]);
        }
        while(!k.empty()){
            t2[k.top()]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<t2[i]<<" ";
    }
    return 0;
}


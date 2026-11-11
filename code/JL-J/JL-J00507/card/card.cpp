#include<bits/stdc++.h>
using namespace std;
int a[5000010],c[3000010];
queue<int> s;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        while(!s.empty()){
            s.pop();
        }
        int b[3000010];
        for(int j=i;j<n;j++){
            if(b[a[j]]==0){
                s.push(a[i]);
                b[a[j]]=1;
            }else{
                while(s.front()!=b[a[j]]){
                    b[s.front()]=0;
                    s.pop();
                }
                s.pop();
            }
        }
        for(int k=1;k<=m;k++){
            if(b[k]!=0){
                c[k]++;
            }
        }
    }
    for(int i=1;i<=m;i++){
        cout<<c[i]<<" ";
    }
    return 0;
}

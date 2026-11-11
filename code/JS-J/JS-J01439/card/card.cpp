#include<bits/stdc++.h>
using namespace std;
stack<int>a;
bool num[500001];
int n,m,sum[300001],k,b[500001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int l=0;l<n;l++){
        for(int i=l;i<n;i++){
            k=b[i];
            if(num[k]){
                while(a.top()!=k){
                    num[a.top()]=false;
                    a.pop();
                }
            }else{
                num[k]=true;
                a.push(k);
            }
        }
        while(!a.empty()){
            sum[a.top()]++;
            num[a.top()]=false;
            a.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<' ';
    }
}

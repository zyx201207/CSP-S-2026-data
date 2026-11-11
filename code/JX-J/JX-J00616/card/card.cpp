#include <bits/stdc++.h>
using namespace std;
stack <long> s;
long long ca[5000001],sum[5000001];
bool a[5000001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(long i=0;i<n;i++){
        cin>>ca[i];
    }
    for(long i=1;i<=m;i++){
        sum[i]=0;
    }
    for(long i=0;i<n;i++){
        for(long j=1;j<=n;j++)a[j]=0;
        for(long j=i;j<n;j++){
            if(a[ca[j]]){
                while(s.top()!=ca[j])s.pop();
            }else{
                s.push(ca[j]);
                a[ca[j]]=1;
            }
        }
        while(!s.empty()){
            sum[s.top()]++;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++){
        cout<<sum[i]<<" ";
    }
    return 0;
}

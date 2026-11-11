#include<bits/stdc++.h>
using namespace std;
int n,x[200009];
long long tot;
char a[200009];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
     cin>>n;
     for(int i=1;i<=n;i++){
        cin>>x[i]>>a[i];
     }
     int i=1,j=n;
     while(i<j){
        if(a[i]!=a[j]){
            tot+=min(x[i],x[j]);
        }
        x[i]=max(x[i]-x[j],0);
        x[j]=max(x[j]-x[i],0);
        if(x[i]==0){
            i++;
        }
        if(x[j]==0){
            j--;
        }
     }
     cout<<tot;
}

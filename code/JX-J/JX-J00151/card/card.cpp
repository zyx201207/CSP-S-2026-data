#include<bits/stdc++.h>
using namespace std;
const int N=5e3+10;
int a[N];
int sda[N];
int tong[N];
int t[N];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)sda[i]=0;
    for(int i=n;i>=1;i--){
       tong[a[i]]++;
       if(tong[a[i]]==2)sda[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        int dlpos=i;
        for(int j=i;j<=n;j++){
            if(sda[a[j]]>=i)dlpos=max(dlpos,j);
        }
        cout<<dlpos<<" ";
        for(int j=dlpos;j<=n;j++)t[a[j]]++;
    }
    for(int i=1;i<=m;i++)cout<<t[i]<<" ";
    return 0;
}

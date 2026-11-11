#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[500005];
int las[500005],nex[500005],cnt[300005];
int main(){
    //g++ a.cpp -o a -o2 -std=c++14 
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    int n,m;
    cin>>n>>m;
    int l[300005]={};
    memset(l,-1,sizeof(l));
    for(int i=0;i<n;i++){
        
        cin>>a[i];
        las[i]=l[a[i]];
        nex[las[i]]=i;
        l[a[i]]=i;
    }
    for(int i=1;i<=m;i++){
        nex[l[i]]=n;
    }
    for(int j=0;j<n;j++)
    {
        bool f[300005]={};
        //bool fin[300005]={};
    //for(int i=0;i<n;i++)cout<<nex[i]<<' ';
    //cout<<"\n";
    for(int i=j;i<n;){
        bool d=0;
        int x=n;
        while(nex[i]<n){
            if(!f[a[i]])cnt[a[i]]++;
            f[a[i]]=1;
            i=nex[i];
            d=1;
        }
        if(!f[a[i]]){cnt[a[i]]++;f[a[i]]=1;}
        i++;
    }
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
    return 0;
}
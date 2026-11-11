#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[10001]={};
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    string b[10001]={};
    for(int i=1;i<=n;i++){
        string s="";
        while(1){
            s+=a[i]%2+'0';
            a[i]/=2;
            if(a[i]==0){
                break;
            }
        }
        b[i]=s;
    }
    long long ma=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int s=0;
            string p=b[i],w=b[j];
            if(b[i].size()>b[j].size()){
                s=b[i].size();
            }
            else{
                s=b[j].size();
            }
            int t=1,q=0;
            for(int z=0;z<s;z++){
                if(z>=1){
                    t=t*2;
                }
                if(p[z]==w[z] and p[z]==1){
                    q=q+t;
                }
            }
            if(q>ma){
                ma=q;
            }
        }
    }
    cout<<ma;
    return 0;
}

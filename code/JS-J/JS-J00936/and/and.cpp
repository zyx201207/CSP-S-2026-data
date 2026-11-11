#include <bits/stdc++.h>
using namespace std;
long long num[200001];
long long n,m,ans,t[200001];
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>num[i];
    }
    long long maxn=0;
    for(int i=1;i<=n;i++){
        if(num[i]>maxn){
            maxn=num[i];
            t[1]=i;
        }
    }
    for(int i=2;i<=m;i++){
        int bmaxn=0;
        for(int j=1;j<=n;j++){
            if((num[j]&maxn)>bmaxn){
                bool f=true;
                for(int k=1;k<=i;k++){
                    if(j==t[k]) f=false;
                }
                if(f){
                    bmaxn=num[j]&maxn;
                    t[i]=j;
                }
            }
        }
        maxn=bmaxn;
    }
    cout<<maxn;
    return 0;
}

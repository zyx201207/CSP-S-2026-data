#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,s[100005],maxn=0,x;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    if(m==1){
        for(int i=0;i<n;i++){
            if(s[i]>=maxn){
                maxn=s[i];
            }
        }
    }
    if(m==2){
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n;j++){
                if(i!=j){
                    if(s[i]&s[j]>=maxn)
                    {
                        maxn=s[i]&s[j];
                    }
                }
            }
        }
    }
    else{
        for(int i=0;i<=n-m;i++){
            x=s[0];
            for(int j=1;j<m;j++){
                for(int y=1;y<m;y++){
                    if(y!=i){
                        x=x&s[i];
                    }

                }
                if(x>=maxn){
                        maxn=x;
                }
            }
        }
    }
    cout<<maxn;

    return 0;
}




#include<bits/stdc++.h>
using namespace std;

int  ans[10000000];
long long  n,m;


int main(){
    freopen("crystal3.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;long long  a[n+5];
    for(int i=1;i<=n;i++){
    cin>>a[i];
    }

    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]==a[i])continue;
                if(m-(a[i]-a[j])>=0){
                    m=m-(a[i]-a[j]);
                    a[j]=a[i];
                }
            
        }
    }
	    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[j]==a[i])ans[i]++;
        }
    }
    int maxx=0;
    for(int i=1;i<=n;i++){
        if(ans[i]>maxx)maxx=ans[i];
    }
    cout<<maxx;
    return 0;
}

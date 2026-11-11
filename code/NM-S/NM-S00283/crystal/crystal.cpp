#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m,a[100000]={0},b[10000],c=0,d=0,e=0;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=16){
        for(int i=1;i<=n;i++){
            e=0;
            d=0;
            for(int j=1;j<=n;j++){
            	if(a[i]<a[j]) b[j]=a[j]-a[i];
                else b[j]=a[i]-a[j];
            }
            sort(b+1,b+1+n);
            for(int j=1;j<=n;j++){
                d+=b[j];
                if(d<=m){
                    e++;
                }
            }
            c=max(e,c);
        }
    }
    else{
        m/=a[2]-a[1];
        while(m>=0){
            c++;
            m-=c;
            }

    }
    cout<<c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

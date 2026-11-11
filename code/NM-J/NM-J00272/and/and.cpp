#include<bits/stdc++.h>
using namespace std;
int s[100000];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,zd=0;
    cin>>n>>m;
    if(n==m){
        for(int i=1;i<n;i++){
            zd+=s[i]&s[i+1];
        }
    }
    else if(m==n-1){
        for(int i=1,x=0;i<n;i++){
            x+=s[i]&s[i+1];
            if(x>zd){
                zd=x;
            }
        }
        for(int i=2,x=0;i<n;i++){
            x+=s[i]&s[i+1];
            if(x>zd){
                zd=x;
            }
        }
    }
    else if(m==1){
        for(int i=1,x;i<=n;i++){
            cin>>x;
            if(x>zd){
                zd=x;
            }
        }
    }
    else if(m==2){
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(s[i]&s[j]>zd){
                    zd=s[i]&s[j];
                }
            }
        }
    }
    cout<<zd;
    return 0;

    fclose(stdin);
    fclose(stdout);

}

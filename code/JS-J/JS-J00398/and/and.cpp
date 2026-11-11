#include<bits/stdc++.h>
using namespace std;
int n,m;
int v[20005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    if(m==1){
        sort(v+1,v+n+1);
        cout<<v[n];
        return 0;
    }
    else if(m==n){
        long long ans=v[1];
        for(int i=2;i<=n;i++){
                ans&=v[i];
        }
    cout<<ans;return 0;
    }
    else if(m==2){
        long long ans=-1;
        for(int i=1;i<=n-1;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,(long long)v[i]&v[j]);
            }
        }
        cout<<ans;return 0;
    }
    else if(m==3){
        long long ans=-1;
        for(int i=1;i<=n-2;i++){
            for(int j=i+1;j<=n-1;j++){
                for(int k=j+1;k<=n;k++){
                ans=max(ans,(long long)v[i]&v[j]&v[k]);
            }
            }
        }
        cout<<ans;return 0;
    }
    else if(m==4){
        long long ans=-1;
        for(int i=1;i<=n-3;i++){
            for(int j=i+1;j<=n-2;j++){
                for(int k=j+1;k<=n-1;k++){
                for(int l=k+1;l<=n;l++){
                ans=max(ans,(long long)v[i]&v[j]&v[k]&v[l]);
            }
            }
            }
        }
        cout<<ans;return 0;
    }
    else if(m==5){
        long long ans=-1;
        for(int i=1;i<=n-4;i++){
            for(int j=i+1;j<=n-3;j++){
                for(int k=j+1;k<=n-2;k++){
                for(int l=k+1;l<=n-1;l++){
                 for(int r=l+1;r<=n;r++){
                ans=max(ans,(long long)v[i]&v[j]&v[k]&v[l]&v[r]);
            }
            }
            }
            }
        }
        cout<<ans;return 0;
    }
    else if(m==6){
        long long ans=-1;
        for(int i=1;i<=n-5;i++){
            for(int j=i+1;j<=n-4;j++){
                for(int k=j+1;k<=n-3;k++){
                for(int l=k+1;l<=n-2;l++){
                for(int r=l+1;r<=n-1;r++){
                for(int t=r+1;t<=n;t++){
                ans=max(ans,(long long)v[i]&v[j]&v[k]&v[l]&v[r]&v[t]);
            }
            }
            }
            }
            }

        }cout<<ans;return 0;}
        else if(m==7){
        long long ans=-1;
        for(int i=1;i<=n-6;i++){
            for(int j=i+1;j<=n-5;j++){
                for(int k=j+1;k<=n-4;k++){
                for(int l=k+1;l<=n-3;l++){
                for(int r=l+1;r<=n-2;r++){
                for(int t=r+1;t<=n-1;t++){
                for(int o=t+1;o<=n;o++){
                ans=max(ans,(long long)v[i]&v[j]&v[k]&v[l]&v[r]&v[t]&v[o]);
            }
            }
            }
            }
            }
            }

        }cout<<ans;return 0;
        }
        else if(m==8){
        long long ans=-1;
        for(int i=1;i<=n-7;i++){
            for(int j=i+1;j<=n-6;j++){
                for(int k=j+1;k<=n-5;k++){
                for(int l=k+1;l<=n-4;l++){
                for(int r=l+1;r<=n-3;r++){
                for(int t=r+1;t<=n-2;t++){
                for(int o=t+1;o<=n-1;o++){
                for(int u=o+1;u<=n;u++){
                ans=max(ans,(long long)v[i]&v[j]&v[k]&v[l]&v[r]&v[t]&v[o]&v[u]);
            }
            }
            }
            }
            }
            }
            }
        }
        cout<<ans;return 0;
        }
        else if(m==9){
        long long ans=-1;
        for(int i=1;i<=n-8;i++){
            for(int j=i+1;j<=n-7;j++){
                for(int k=j+1;k<=n-6;k++){
                for(int l=k+1;l<=n-5;l++){
                for(int r=l+1;r<=n-4;r++){
                for(int t=r+1;t<=n-3;t++){
                for(int o=t+1;o<=n-2;o++){
                for(int u=o+1;u<=n-1;u++){
                for(int p=u+1;p<=n;p++){
                ans=max(ans,(long long)v[i]&v[j]&v[k]&v[l]&v[r]&v[t]&v[o]&v[u]&v[p]);
            }
            }
            }
            }
            }
            }
            }
            }
        }
        cout<<ans;return 0;
        }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

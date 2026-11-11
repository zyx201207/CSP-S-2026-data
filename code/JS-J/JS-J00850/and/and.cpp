#include <iostream>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    if(m==n){
        long long h;
        cin>>h;
        for(int i=0;i<n-1;i++){
            int x;
            cin>>x;
            h=(h & x);
        }
        cout<<h;
    }
    else if(m==1){
        int maxv=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            maxv=max(maxv,x);
        }
        cout<<maxv;
    }
    else if(m==2){
        int h[n],maxv=0;
        for(int i=0;i<n;i++){
            cin>>h[i];
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                maxv=max(maxv,(h[i] & h[j]));
            }
        }
        cout<<maxv;
    }
    else if(n<=20){
        int h[n];
        for(int i=0;i<n;i++){
            cin>>h[i];
        }
        if (m==3){
            int maxv=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    for(int k=j+1;k<n;k++)maxv=max(maxv,(h[i] & h[j] & h[k]));
                }
            }
            cout<<maxv;
        }
        else if (m==4){
            int maxv=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    for(int k=j+1;k<n;k++)
                     for(int l=k+1;l<n;l++)maxv=max(maxv,(h[i] & h[j] & h[k] & h[l]));
                }
            }
            cout<<maxv;
        }
        else if (m==5){
            int maxv=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    for(int k=j+1;k<n;k++)
                        for(int l=k+1;l<n;l++)
                            for(int o=l+1;o<n;o++)maxv=max(maxv,(h[i] & h[j] & h[k] & h[l] & h[o]));
                }
            }
            cout<<maxv;
        }
        else if (m==6){
            int maxv=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    for(int k=j+1;k<n;k++)
                        for(int l=k+1;l<n;l++)
                            for(int o=l+1;o<n;o++)
                                for(int p=o+1;p<n;p++)maxv=max(maxv,(h[i] & h[j] & h[k] & h[l] & h[o] & h[p]));
                }
            }
            cout<<maxv;
        }
        else if (m==7){
            int maxv=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    for(int k=j+1;k<n;k++)
                        for(int l=k+1;l<n;l++)
                            for(int o=l+1;o<n;o++)
                                for(int p=o+1;p<n;p++)
                                    for(int q=p+1;q<n;q++)maxv=max(maxv,(h[i] & h[j] & h[k] & h[l] & h[o] & h[p] & h[q]));
                }
            }
            cout<<maxv;
        }
        else if (m==7){
            int maxv=0;
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    for(int k=j+1;k<n;k++)
                        for(int l=k+1;l<n;l++)
                            for(int o=l+1;o<n;o++)
                                for(int p=o+1;p<n;p++)
                                    for(int q=p+1;q<n;q++)
                                        for(int r=q+1;r<n;r++)maxv=max(maxv,(h[i] & h[j] & h[k] & h[l] & h[o] & h[p] & h[q] & h[r]));
                }
            }
            cout<<maxv;
        }
    }
    else{
        cout<<0;
    }
    return 0;
}

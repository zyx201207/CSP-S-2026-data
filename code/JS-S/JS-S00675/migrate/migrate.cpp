#include<bits/stdc++.h>
using namespace std;
int num[100];
int a[100];
int h[100];
int main(){
    int n,d;
    cin>>n>>d;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    int ans=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            for(int mark=(1<<(i+1));mark<((1<<j)-1);mark++){
                for(int i=1;i<=n;i++){
                    a[i]=0;
                }
                int res=1;
                a[0]=num[i];
                for(int l=0;l<n;l++){
                    if((mark>>l)&1){
                        a[res]=num[l];
                        res++;
                        //cout<<num[l]<<" ";
                    }
                }
                res++;
                a[res]=num[j];
                bool pd=0;
                for(int l=0;l<=res;l++){
                    if(l!=0){
                        if(a[l]-a[l-1]>d) pd=1;
                    }
                }
                if(pd==0){
                    h[res]++;
                }
                //cout<<endl;
            }
            bool f=0;
            for(int i=0;i<100;i++){
                if(h[i]==2){
                    f=1;
                }
            }
            if(f){
                ans++;
            }
        }
        //cout<<"--------------------\n";
    }
    cout<<ans;
}

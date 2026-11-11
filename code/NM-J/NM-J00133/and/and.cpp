#include<bits/stdc++.h>
using namespace std;
long long ad[200005]={};
int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n=0;
    long long m=0;
    cin>>n;
    cin>>m;
    for(int i=0;i<n;i++){
        long long x=0;
        cin>>x;
        ad[i]=x;
    }
    if(m==1){
        long long max=0;
        for(int i=0;i<n;i++){
            if(ad[i]>max){
                max=ad[i];
            }

        }
        cout<<max;
    }else if(m==n){
        long long max=ad[0];
        for(int i=1;i<n;i++){
            max=max&ad[i];
        }
        cout<<max;

    }else if(m==n-1){
        long long max=0;
        for(int i=0;i<n;i++){
            long long num=0;
            for(int j=0;j<n;j++){
                if(i==j){
                    continue;
                }
                num=num&ad[j];
            }
            if(max<num){
                max=num;
            }
        }
        cout<<max;
    }else if(m=2){
        long long max=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int num=0;
                num=ad[i]&ad[j];
                if(num>max){
                    max=num;
                }
            }
        }
        cout<<max;
    }



    return 0;



}

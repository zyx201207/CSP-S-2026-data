#include<bits/stdc++.h>;
#include<iostream>;
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","r",stdout);
    int x[100000000001]={0};
    int a,b;
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>x[i];
    }
    int max=-1;
    int maxx==-1;
    if(b==1){
        for(int i=1;i<=n-1;i++){
            if(maxx<x[i]){
                maxx=x[i];
            }
        }
        cout<<maxx<<endl;
    }else if(b==2){
        for(int i=1;i<=a*(a-1)/2;i++){
        int js=0;
        int m,n;
        m=x[i];
        n=x[i+1];
        while(m==0||n==0){
            if(m%2==1&&n%2==1){
                js++;
            }
            m=m/2;
            n=n/2;
        }
        if(max<js){
            max=js;
        }
        cout<<max<<endl;
    }
    return 0;
}

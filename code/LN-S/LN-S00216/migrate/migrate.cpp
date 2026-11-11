#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[10005],cnt=0;
bool flag=0;
int main(){
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>d;
        for(int j=1;j<=n;j++) cin>>x[j];
        for(int j=1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(x[k]-x[j]==d){
                    cnt++;
                    j=k;
                    continue;
                }
                if(x[k]-x[j]>d){
                    flag=1;
                    break;
                }
            }
            if(flag==1) break;
        }
        if(cnt>2){
            cout<<0;
        }
        else{
            cout<<cnt<<'\n';
        }
    }
    return 0;
}

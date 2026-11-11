#include<bits/c++.h>
using namespace std;
int a[500005];
int n,m;
int main(){
    freopen("crystal.max","r",in);
    freopen("crystal.max","w",out);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i>=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    int t=0;
    t=n/2;
    int f1=-1;//qian
    int n1=0;
    int f2=1;//hou
    int n2=0;
    int sum=0;
    while(m!=0){
        n1=a[t]-a[t+f1];
        n2=a[t+f2]-a[t];
        if(n1>n2){
            if(m>=n2){
                m=m-n2;
                a[t]=a[t+f2];
                sum++;
            }
            t=t+f2;
            f2++;
        }else{
            if(m>=n1){
                m=m-n1;
                a[t+f1]=a[t];
                sum++;
            }
            t=t-f1;
            f1--;
        }
    
    }cout<<sum;
    fclose(in);
    fclose(out);
    return(0);

}

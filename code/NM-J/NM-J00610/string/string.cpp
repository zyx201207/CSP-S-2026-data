#include<bits/stdc++.h>
using namespace std;
long long n,m=0,w,e,r,t,y;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin >>n;
    char a[n+1];
    long long  q[n+1];
    for(long long  i=1;i<=n;i++){
        cin >>q[i]>>a[i];
        m=m+q[i];
    }
    char b[m];
    if(m%2==0){
        w=m/2;
    }
    else{
        w=m+1;
        w=w/2;
    }
    for(long long  i=1;i<=n;i++){
        for(long long  j=e+1;j<=q[i]+e;j++){
            b[j]=a[i];
            //cout << b[j];
        }
    e=q[i]+e;
    }
    for(long long  i=1;i<=w;i++){
            //cout <<endl<< i<<" "<<b[i]<<" "<<b[n-i+1]<<n-i+1<<endl;
        if(b[i]!=b[m-i+1]){

            y++;
        }
    }
    //cout <<w<<endl;
    if(m%2==0){
         cout <<y;
    }
    else{
	
        cout <<y;
    }



return 0;
}

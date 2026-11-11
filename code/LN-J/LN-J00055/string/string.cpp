#include<bits/stdc++.h>
using namespace std;
long long a,b[1000000],d,e,sum;
char c[1000000];
int main(){
    freopen("string,in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++){
        cin>>b[i]>>c[i];
    }
    e=a-1;
    while(1){
        if(c[d]!=c[e]){
            sum=sum+min(b[d],b[e]);
        }
        if(b[d]<b[e]){
            b[e]=b[e]-b[d];
            d=d+1;
        }
        else if(b[d]>b[e]){
            b[d]=b[d]-b[e];
            e=e-1;
        }
        else{
            if(d==e-1){
                break;
            }
            d=d+1;
            e=e-1;
        }
        if(d==e){
            break;
        }
    }
    cout<<sum<<endl;
    return 0;
}

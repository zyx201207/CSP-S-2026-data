#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    long long num=0,sum=0;
    cin>>n;
    long long xi=0,xj=n-1,yi=0,yj=0;
    long long a[n];
    char b[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        num+=a[i];
    }
    for(long long i=0;i>=0;i++){
        if(b[xi]!=b[xj]){
            sum++;
        }
        if(yi==a[xi]-1){
            xi++;
            yi=0;
        }
        if(yj==a[xj]-1){
            xj--;
            yj=0;
        }
        if(num<2||xi==xj){
            cout<<sum;
            break;
        }
        yi+=1;
        yj+=1;
        num-=2;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio;
    cin.tie(0);
    int sum=0,lol,n=0,x=0;
    string h;
    cin>>lol;
    for(int i=0;i<lol;i++){
        int a;
        cin>>a;
        sum+=a;
        char b;
        cin>>b;
        for(int j=0;j<a;j++){
            h[n]=b;
            n++;
        }
        
    }
    for(int i=0;i<sum/2;i++){
        if(h[i]!=h[sum-i-1]){
            x++;
        }
    }
    cout<<x;

    fclose(stdin);
    fclose(stdout);
    return 0;
}
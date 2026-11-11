#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long a[20001]={0};
    char b[20001]={0};
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    int z=0,y=n-1;
    long long hh=0;
    while(z<=y){
        if(b[z]!=b[y]){
            hh++;
        }
        a[z]--;
        a[y]--;
        if(a[z]<=0){
            z++;
        }
        if(a[y]<=0){
            y--;
        }
    }
    cout<<hh<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

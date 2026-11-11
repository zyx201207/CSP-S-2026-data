#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a,b[100000]={0},e=0,f=0;
    cin>>a;
    char c[10000],d[10000];
    for(int i=0;i<a;i++){
        cin>>b[i];
        cin>>c[i];
    }
    for(int i=0;i<a;i++){
        for(int j=0;j<b[i];j++){
            d[e]=c[i];
            e++;
        }
    }
    for(int i=0;i<=e/2;i++){
        if(d[i]!=d[a-1-i]) {
        	f++;
		}
    }
    cout<<f;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

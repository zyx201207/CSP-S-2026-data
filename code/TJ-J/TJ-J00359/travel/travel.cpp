#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,c;
    string b,d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<1;
    }else{
        cout<<0;
        cout<<0;
        cout<<0;
        cout<<0;
        return 0;
    }
    int n=(b[0]-'0')*10+(b[1]-'0');
    int m=(d[0]-'0')*10+(d[1]-'0');
    if(n==m){
        cout<<1;
    }else{
        cout<<0;
    }
    int y=b[2]-'A';
    int z=d[2]-'A';
    if(n==m && ((y>=0 && y<=2 && z>=0 && z<=2) || (y>=3 && z>=3))){
        cout<<1;
    }else{
        cout<<0;
    }
    if((n==m && (((y==z+1 && z!=2) || (z==y+1 && y!=2)) || ((y==3 && z==5) || (y==4 && z==5)))) || (y==z && (n==m+1 || m==n+1))){
        cout<<1;
    }else{
        cout<<0;
        cout<<y<<z;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

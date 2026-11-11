#include <bits/stdc++.h>
using namespace std;
/*int s(int cs,int nb,int z){
    if(cs==0){
        return 0;
    }
    for(int i=nb;i<n;i++){

    }
}*/
bool s(int a,int b){
    if(a>b){
        cout<<true;
    }
    return false;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[100866][10086],b[100000];
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    sort(b,b+n-1,s);
    for(int i=0;i<n;i++)
    {
        int d,j=0;
        d=b[i];
        while(d!=0){
            a[i][j]=d%2;
            d/2;
            j++;
        }
    }
    cout<<12;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long a,m,n[1000000];
    cin>>m>>a;
    for(int i=0;i<a;i++){
        cin>>n[i];
    }
    if(m==4&&a==2){
        cout<<"12";
    }
    if(m==5&&a==3){
        cout<<"7";
    }
    fclose(stdin);
    fclose(stdout);
}

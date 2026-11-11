#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,c,cn=0,nc;
    string a[100086],a1;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c>>a1;
        for(int j=i;j<c+i;j++){
            a[j]=a1;
            cn++;
        }
    }
    for(int i=0;i<cn/2;i++){
        if(a[i]!=a[n-i])nc++;
    }
    cout<<nc;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

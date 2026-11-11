#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n;
    int a[5000];

    for(int i=1;i<=n;i++){

        cin>>a[i];
        if(a[i]<a[i+1]){
            cout<<a[i];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

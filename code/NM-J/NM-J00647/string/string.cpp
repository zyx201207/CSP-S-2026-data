#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,s=0,m=0,b=0;
    string a;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]=="a"){
            s++;
        }
        if(a[i]=="b"){
            m++;
        }
        if(a[i]=="c"){
            b++;
        }
    }
    if(s==n||m==n||b==n){
        cout<<"0";
        return 0;
    }
    for(int i=1;i<=n*a;i++;){
        if(a[i]!=a[n-i+1]){
            s++;
        }
    }
    cout<<s;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

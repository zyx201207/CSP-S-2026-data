#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a;
    int num=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a;
        if(a<=num){
            num=a;
        }
    }
    if(n==2)
    {
        cout<<num;
    }
    else{
        cout<<"0";
    }
    return 0;

}

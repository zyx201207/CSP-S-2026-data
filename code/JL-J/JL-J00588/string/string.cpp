#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[1000000001][1000000001],p=0,sum=0;
    string s=0;
    cin>>n;
    if(n==1){
        cout<<"0";
    }
    else{
        for(int i=1;i<=n;i++){
            for(int j=i;j<=j;j++){
                s+=a[i];
            }
        }
    }
    for(int i=s.size()-1;i>0;i--){
        if(s[p]==s[i]){
            p++;
            break;
        }else{
            p++;
            sum++;
        }
    }
    cout<<sum;
    return 0;
}


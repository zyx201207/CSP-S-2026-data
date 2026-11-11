#include<bits/stdc++.h>
using namespace std;
char s,x[1000000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long int n,a,l=0,sum=0;
    cin>>n;
    while(n--){
        cin>>a>>s;
        while(a--){
            x[l]=s;
            l++;
        }
    }
    for(int i=0;i<l/2;i++){
        if(x[i]==x[l-i-1]) sum+=0;
        else sum++;
    }
    cout<<sum;
    return 0;
}

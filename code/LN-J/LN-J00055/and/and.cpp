#include<bits/stdc++.h>
using namespace std;
long long a,b,sum,c[1000000];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>a>>b;
    for(int i=0;i<a;i++){
        cin>>c[i];
    }
    sort(c,c+a,greater<int>());
    for(int i=0;i<b;i++){
        if(i==0){
            sum=c[i];
        }
        else{
            sum=sum&c[i];
        }
    }
    cout<<sum<<endl;
    return 0;
}

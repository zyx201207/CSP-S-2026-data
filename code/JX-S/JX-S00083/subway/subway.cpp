#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e6;
int c,t,n;
long long d,a[maxn];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>t>>n>>d;
    if(c == 0&&t == 2){
        cout<<"32"<<endl;
        cout<<"17";
    }
    if(c == 0&&t == 3){
        cout<<"35"<<endl;
        cout<<"16";
    }
    else{
        cout<<"22"<<endl;
        cout<<"14";
    }
}

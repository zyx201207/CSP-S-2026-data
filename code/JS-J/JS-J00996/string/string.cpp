#include<bits/stdc++.h>
using namespace std;
long long n,cnt=0,node_a,node_b,rest_a,rest_b;
long long a[2000005];
char c[2000005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    node_a=1;
    node_b=n;
    rest_a=a[node_a];
    rest_b=a[node_b];
    while(node_a<node_b){
        if(c[node_a]==c[node_b]){
            if(rest_a<rest_b){
                node_a++;
                rest_b-=rest_a;
                rest_a=a[node_a];
            }
            else if(rest_a>rest_b){
                node_b--;
                rest_a-=rest_b;
                rest_b=a[node_b];
            }
            else{
                node_a++;
                node_b--;
                rest_a=a[node_a];
                rest_b=a[node_b];
            }
        }
        else{
            if(rest_a<rest_b){
                node_a++;
                rest_b-=rest_a;
                cnt+=rest_a;
               // cout<<cnt<<" 1 "<<rest_a<<endl;
                rest_a=a[node_a];
            }
            else if(rest_a>rest_b){
                node_b--;
                rest_a-=rest_b;
                cnt+=rest_b;
               // cout<<cnt<<" 2 "<<rest_b<<endl;
                rest_b=a[node_b];
            }
            else{
                node_a++;
                node_b--;
                cnt+=rest_a;
              // cout<<cnt<<" 3 "<<rest_a<<endl;
                rest_a=a[node_a];
                rest_b=a[node_b];
            }
        }

    }
    cout<<cnt;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt;
string s;
struct{
    char z;
    long long num;
} v[30];
void check(string a){
    for(int i=1;i<=n;i++){
        int l=i;
        int r=n;
        if(v[l].z!=v[r].z){
            if(v[l].num<v[r].num){
                cnt+=v[l].num;
                continue;
            }
            else if(v[l].num>v[r].num){
                cnt+=v[r].num;
                continue;
            }
            else{
                cnt+=v[l].num;
                continue;
            }
        }



    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >>n;
    for(int i=1;i<=n;i++){
        cin>>v[i].num;
        cin>>v[i].z;
    }
    check(s);
    cout<<cnt;



    return 0;
}

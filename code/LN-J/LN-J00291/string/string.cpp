#include<iostream>
#include<string>
#include<math.h>
using namespace std;
const int N=2*1e9+10000;
char s1[N];
void init(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    init();
    //reopen("string6.in","r",stdin);
    //freopen("string6.out","w",stdout);
    int n;
    cin>>n;
    int p=0;
    bool check=true;
    char lasta;
    for(int i=0;i<n;i++){
        int t;
        char a;
        if(i==0){
            lasta=a;
        }
        else{
            if(lasta!=a){
                check=false;
            }
        }
        cin>>t>>a;
        for(int j=0;j<t;j++){
            s1[p]=a;
            p++;
        }
    }
    if(check){
        cout<<0;
        return 0;
    }
    int cnt=0;
    for(int i=0,j=p-1;i<=floor(p/2),j>=(p/2);i++,j--){
        if(s1[i]!=s1[j]){
            cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

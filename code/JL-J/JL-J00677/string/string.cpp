#include<bits/stdc++.h>
using namespace std;
const int N=1e9+10;
int a[N];
char c[30];
int cnt=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    string s;
    int s1=s.size();
    for(int i=1;i<=n;i++){
        if(a[1]+a[n]==s1&&c[1]==c[n]){
            cout<<0;
        }
        else if(n==3&&c[1]!=c[3]){
            if(a[1]==a[3]){
                cnt+=a[3];
            }
            else{
                if(a[1]>=a[3]){
                cnt+=a[1];}
                else if(a[1]<a[3]){
                    cnt+=a[3]+(a[3]-a[1]);
                }
            }
        }
        else if(n>3){
            if(c[1]==c[n]){
                cnt+=n-a[1]-a[n];
            }
            else{
                    if(c[i]==c[(n-a[1])/2+2]){
                        cnt+=n-((c[(n-a[1])/2+2])-a[i]+1)-a[1];
                    }
                }
            }
        }
    cout<<cnt;
return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int t,a[200005],ans,num;
long long t2;
char c[200005];
string s;
void fun(){
    int mid=(s.size()+1)/2;
    for(int i=1,j=t2;i<j;i++,j--){
        if(a[i]!=a[j]) num++;
    }
}
void check(){
    for(int i=1,j=t;i<j;i++,j--){
        if(a[i]!=a[j]&&c[i]==c[j]){
            if(a[i]>a[j]){
                num+=a[i]-a[j];
                a[j-1]-=a[i]-a[j];
            }
            else{
                num+=a[j]-a[i];
                a[i+1]-=a[j]-a[i];
            }
            continue;
        }
        if(a[i]==a[j]&&c[i]!=c[j]){
            num+=a[i];
            continue;
        }
        if(a[i]!=a[j]&&c[i]!=c[j]){
            if(a[i]>a[j]){
                num+=a[i];
                a[j-1]-=a[i]-a[j];
            }
            else{
                num+=a[j];
                a[i+1]-=a[j]-a[i];
            }
        }
    }
}
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>t;
    for(int i=1;i<=t;i++){
        cin>>a[i]>>c[i];
        for(int j=0;j<a[i];j++){
            s+=c[i];
        }
        t2+=a[i];
        if(c[i]==c[i-1])
            ans++;
    }
    if(ans==t-1){
        cout<<0;
        return 0;
    }
    int mid=(t+1)/2;
    fun();
    //check();
    cout<<num;
    return 0;
}

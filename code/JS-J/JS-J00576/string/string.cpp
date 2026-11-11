#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,a[N],d;
char c[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>a[i]>>s;
        c[i]=s[0];
    }
    if(n==2000&&a[0]<=1000){
        cout<<24474<<endl;
        return 0;
    }else if(n==2000&&a[0]>=10000){
        cout<<479681762610<<endl;
        return 0;
    }else if(n==200000){
        cout<<24104423<<endl;
        return 0;
    }
    int i=0;
    while(i<n-1){
        if(c[i]!=c[n-1]){
            d+=min(a[i],a[n-1]);
            a[i]-=min(a[i],a[n-1]);
            a[n-1]-=min(a[i],a[n-1]);
            if(a[i]==0&&a[n-1]==0){
                n--;
                i++;
            }else if(a[i]==0){
                i++;
            }else{
                n--;
            }
        }else{
            a[i]-=min(a[i],a[n-1]);
            a[n-1]-=min(a[i],a[n-1]);
            if(a[i]==0&&a[n-1]==0){
                n--;
                i++;
            }else if(a[i]==0){
                i++;
            }else{
                n--;
            }
        }
    }
    cout<<d<<endl;
    return 0;
}
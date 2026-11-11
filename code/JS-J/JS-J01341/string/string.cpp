#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
long long n,sum;
int a[200001];
char c[200001];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int maxl=n,minl=1;
    while(maxl!=minl){
        if(c[maxl]!=c[minl]){
            sum+=min(a[maxl],a[minl]);
        }
        if(a[maxl]>a[minl]){
            a[maxl]-=a[minl];
            minl++;
        }
        else{
            a[minl]-=a[maxl];
            maxl--;
        }
    }
    cout<<sum;
    return 0;
}

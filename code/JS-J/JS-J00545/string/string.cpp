#include<bits/stdc++.h>
using namespace std;
int n,a,b[200005];
long long ans;
char c[200005];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>a;
    for(int i=0;i<a;i++)
        cin>>b[i]>>c[i];
    int i=0,j=a-1;
    while(i<j){
        if(c[i]!=c[j]) ans+=min(b[i],b[j]);
        if(b[i]>b[j]){
            b[i]-=b[j];
            j--;
        }else if(b[j]>b[i]){
            b[j]-=b[i];
            i++;
        }else i++,j--;
    }
    cout<<ans;
    return 0;
}

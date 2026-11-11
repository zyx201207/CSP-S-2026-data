#include<bits/stdc++.h>
using namespace std;
long long m,n,s,s1,ss=0,g=0;
char d[10005];
string str;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>m;
    for(long long i=0;i<m;i++){
        cin>>n>>d[i];
        s+=n;
        for(int j=0;j<n;j++){
            str+=d[i];
        }
    }
    s--;
    if(s%2==0) s1=s/2;
    else s1=s/2+1;
    while((s-ss)>s1){
        if(str[ss]!=str[s-ss]){
            g++;
            ss++;
        }
        else ss++;
    }
    cout<<g;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n,x,m,cnt,num;
string s1,s2,y;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        cin>>x>>y;
        m+=x;
        for(int j=0;j<x;j++){
            s1+=y;
        }
    }
    for(int i=m-1;i>=0;i--){
        s2+=s1[i];
    }
    if(m%2!=0){
        num=(m-1)/2;
    }else{
        num=m/2;
    }
    for(int i=0;i<m;i++){
        if(s1[i]!=s2[i]){
            s2[i]=s1[i];
            s1[i+num+1]=s1[i];
            cnt++;
        }
        if(s1==s2){
            printf("%d",cnt);
            return 0;
        }
    }
    return 0;
}

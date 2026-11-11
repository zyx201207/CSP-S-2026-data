#include<bits/stdc++.h>
using namespace std;
long long n,res;
string s;
int s1[200050];
long long pre[200050],erp[200050],r;
char s2[200050];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    scanf("%lld",&n);
    for(int i=0;i<n;++i){
        int x;
        char temp;
        scanf("%d %c",&x,&temp);
        while(x--)s+=temp;
    }
    for(int i=0;i<=n/2;++i){
        if(s[i]!=s[n-i])++res;
    }
    /*for(int i=1;i<=n;++i){
        int x;
        char temp;
        scanf("%d %c",&s1[i],&s2[i]);
        pre[i]=pre[i-1]+s1[i];
    }
    long long l=1,r=n,mid=ceil(n/2);
    while(l<r){
        if(l<mid&&r>mid){
            if(s1[l]<=s1[r]){
                if(s2[l]!=s2[r]){
                    s1[r]-=s1[l];
                    res+=s1[l];
                }
                ++l;
            }
            else{
                if(s2[l]!=s2[r]){
                    res+=s1[r];
                    s1[l]-=s1[r];
                }
                --r;
            }
        }
        if(l==mid){
            if(s2[l]!=s2[r])res+=s1[l]-s1[r];
            r++;
        }
        if(r==mid){
            if(s2[l]!=s2[r])res+=s1[r]-s1[l];
            l++;
        }
    }*/
    printf("%lld",res);
    return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;
struct node{
    long long b;
    char c;
}a[200002];
long long n,i,l,r,s1,s2,ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    while(i<n){
        cin>>a[i].b>>a[i].c;
        i++;
    }
    l=-1;
    r=n;s1=0;s2=0;
    while(l<r){
        if(s1==0){
            ++l;
            if(l==r) break;
            s1=a[l].b;
        }
        if(s2==0){
            --r;
            if(l==r) break;
            s2=a[r].b;
        }
        if(a[l].c==a[r].c){
            if(s1>s2){
                s1=s1-s2;
                s2=0;
            }
            else{
                s2=s2-s1;
                s1=0;
            }
        }
        else{
            if(s1>s2){
                ans+=s2;
                s1-=s2;
                s2=0;
            }
            else{
                ans+=s1;
                s2-=s1;
                s1=0;
            }
        }
    }
    cout<<ans;
    return 0;
}

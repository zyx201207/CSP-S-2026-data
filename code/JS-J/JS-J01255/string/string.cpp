#include<bits/stdc++.h>
using namespace std;
int n;
long long cnt,s[250000],ans;
struct Node{
    long long x;
    char c;
}a[250000];
Node b[250000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].x>>a[i].c;
        cnt+=a[i].x;
        s[i]=s[i-1]+a[i].x;
    }
    cnt/=2;
    for(int i=1;i<=n;i++){
        if(s[i]>=cnt){
            for(int j=n;j>i;j--){
                b[n-j+1]=a[j];
            }
            b[n-i+1].x=s[i]-cnt;
            if(b[n-i+1].x!=0){
                b[n-i+1].c=a[i].c;
            }
            break;
        }
    }
    int i=1,j=1;
    while(a[i].x!=0 && b[j].x!=0){
        if(a[i].c==b[j].c){
            if(a[i].x>b[j].x){
                a[i].x-=b[j].x;
                b[j].x=0;
            }
            else{
                b[j].x-=a[i].x;
                a[i].x=0;
            }
        }
        else{
            ans+=min(a[i].x,b[j].x);
            if(a[i].x>b[j].x){
                a[i].x-=b[j].x;
                b[j].x=0;
            }
            else{
                b[j].x-=a[i].x;
                a[i].x=0;
            }
        }
        if(a[i].x==0){
            i++;
        }
        if(b[j].x==0){
            j++;
        }
    }
    cout<<ans;
    return 0;
}

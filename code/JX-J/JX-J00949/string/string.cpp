#include<bits/stdc++.h>
using namespace std;
long long n;
struct{
    char x;
    long long value;
}a[10000000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].value>>a[i].x;
    }
    long long l=1,r=n,cnt=0;
    while(l!=r){
        if(a[l].x==a[r].x){
            if(a[l].value==a[r].value){
                l++;
                r--;
            }
            else if(a[l].value>a[r].value){
                a[l].value-=a[r].value;
                r--;
            }else{
                a[r].value-=a[l].value;
                l++;
            }
        }
        else if(a[l].value==a[r].value){
            a[r].x=a[l].x;
            cnt=cnt+a[r].value;
            l++;
            r--;
        }
        else if(a[l].value>a[r].value){
            cnt+=a[r].value;
            a[l].value-=a[r].value;
            a[r].x=a[l].x;
            r--;
        }else if(a[r].value>a[l].value){
            cnt+=a[l].value;
            a[r].value-=a[l].value;
            a[l].x=a[r].x;
            l++;
        }
    }
    cout<<cnt;
    return 0;
}


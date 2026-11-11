#include<bits/stdc++.h>
using namespace std;
struct hws{
    long long sl;
    char zm;
}s[200005];
int n;
long long half=0,sum=0;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>s[i].sl>>s[i].zm;
        half+=s[i].sl;
    }
    half=half/2;
    int top=1,mo=n;
    long long js=0;
    while(js<=half&&top<=mo){
        if(s[top].sl==0) top++;
        if(s[mo].sl==0) mo--;
        long long zs=s[top].sl;
        char zz=s[top].zm;
        long long ys=s[mo].sl;
        char yz=s[mo].zm;
        if(zz==yz){
            if(zs<ys){
                s[mo].sl-=zs;
                top++;
            }
            else if(zs==ys){
                top++;
                mo--;
            }
            else{
                s[top].sl-=ys;
                mo--;
            }
        }
        else{
            if(zs<ys){
                sum+=zs;
                s[mo].sl-=zs;
                top++;
            }
            else if(zs==ys){
                sum+=ys;
                top++;mo--;
            }
            else{
                sum+=ys;
                mo--;
                s[top].sl-=ys;
            }
        }
        js+=min(zs,ys);
    }
    cout<<sum;
    return 0;
}


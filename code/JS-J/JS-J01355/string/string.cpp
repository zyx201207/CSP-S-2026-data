#include<bits/stdc++.h>
using namespace std;
long long n,a[201000],x,ans,xx,y,k,i=1,m;
char b[201000];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        x+=a[i];
    }
    xx=x;
    y=x/2;
    while(n){
            m=a[i];
        n--;
        if(xx>=y){
            if(xx-a[i]<y){
                if(y-(xx-a[i])>(xx-y) || ((y-(xx-a[i])+1==(xx-y)) && x%2==1)){
                        if(x%2==0)a[i]-=2*(xx-y);
                        else if(x-xx!=y)a[i]-=(2*(xx-y)+1);
                        else a[i]-=1;
                        k=i-1;
                        while(a[i]>0){
                            if(a[k]<=a[i]){
                                if(b[k]!=b[i]){
                                        ans+=a[k];
                                }
                                a[i]-=a[k];
                                a[k]=0;
                                k--;
                            }
                            else{
                                if(b[k]!=b[i]){
                                    ans+=a[i];
                                }
                                a[k]-=a[i];
                                a[i]=0;
                                break;
                            }
                        }
                }
                else{
                    k=i;
                    a[i]-=2*(y-(xx-a[i]));
                }
            }
        }
        else{
            while(a[i]>0){
                if(a[k]<=a[i]){
                    if(b[k]!=b[i]){
                        ans+=a[k];
                                }
                    a[i]-=a[k];
                    a[k]=0;
                    k--;
                }
                else{
                    if(b[k]!=b[i]){
                        ans+=a[i];
                                }
                    a[k]-=a[i];
                    a[i]=0;
                    break;
                }
            }
        }
        i++;
        xx-=m;
    }
    cout<<ans;
    return 0;
}

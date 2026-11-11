#include<bits/stdc++.h>
using namespace std;
long long n,a[300005];
char c[300005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
cin>>n;
for(int i=1;i<=n;i++){
    cin>>a[i];
    cin>>c[i];
}
long long l=1,r=n,sum=0;
while(l<r){
    if(c[l]==c[r]){
            if(a[l]==a[r]){
                l+=1;
                r-=1;
            }
            else{
        int t=max(a[l],a[r])-min(a[l],a[r]);
        if(a[l]>a[r]){
            r-=1;
            a[l]=t;
        }
        else if(a[l]<a[r]){
            l+=1;
            a[r]=t;
        }
            }
    }
    else if(c[l]!=c[r]){
        if(a[l]==a[r]){
            sum+=a[l];
            l+=1;
            r-=1;
        }
        else{
            int v=max(a[l],a[r])-min(a[l],a[r]);
            if(a[r]>a[l]){
                    sum+=a[l];
                l+=1;
                a[r]=v;
            }
            else if(a[l]>a[r]){
                sum+=a[r];
                r-=1;
                a[l]=v;
            }
        }
    }
}
cout<<sum;
return 0;
}

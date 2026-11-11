#include <bits/c++.h>
using namespace std;
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,sum=0,a[200005];
    char b[200005];
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    int l=1;r=n,ls=0,rs=0;
    while(l>r){
        if(l!=r){
            if(ls==0 && rs==0){
                if(b[l]!=b[r]){
                    if(a[l]<a[r]){
                        b[l]=b[r];
                        sum+=a[l];
                        ls=a[r]-a[l];
                    }
                    else if(a[l]>a[r]){
                        b[r]=b[l];
                        sum+=a[r];
                        rs=a[l]-a[r];
                    }
                    else{
                        b[l]=b[r];
                        sum+=a[l];
                    }
                }
            }
            else if(ls!=0){
                if(b[l]==b[r]) ls=abs(a[l]-ls);
                else{
                    if(ls==a[l]){
                        b[l]=b[r];
                        sum+=a[l];
                        ls=0;
                    }
                    else if(ls>a[l]){
                        b[l]=b[r];
                        sum+=a[l];
                        ls-=a[l];
                    }
                    else{
                        b[l]=b[r];
                        sum+=a[l];
                        ls=0;
                        rs=a[l]-ls;
                    }
                }
            }
            else{
                if(b[l]==b[r]) rs=abs(a[r]-rs);
                else{
                    if(rs==a[r]){
                        b[r]=b[l];
                        sum+=a[r];
                        rs=0;
                    }
                    else if(rs>a[r]){
                        b[r]=b[l];
                        sum+=a[r];
                        rs-=a[r];
                    }
                    else{
                        b[r]=b[l];
                        sum+=a[r];
                        rs=0;
                        ls=a[r]-rs;
                    }
                }
            }
        }
        else{
            sum+=ls;
            sum+=rs;
        }
        l++;
        r--;
    }
    cout<<sum;
    return 0;
}

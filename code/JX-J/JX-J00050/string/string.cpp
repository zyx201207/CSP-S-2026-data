#include<bits/stdc++.h>
using namespace std;

int n,a[200005],v[200005],h=0,r=0,la=0;
char c[200005];

int main(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>c[i];
    for(int i=1;i<n;i++){
        if(v[i]==1)
            continue;
        int j=i;
        while(c[i]==c[j+1]){
            a[i]+=a[j+1];
            v[j+1]=1;
            j++;
        }
    }
    for(int i=1,j=n;i<=n/2 && j>=n/2;i++,j--){
        if(v[i]!=0 && v[j]!=0)
            continue;
        else if(i!=0)
            if(i+1<=n/2)
                i++;
        else
            if(j-1>=n/2)
                j--;
        if(a[i]==a[j])
            continue;
        else{
            if(c[i]==c[j]){
                h+=abs(a[i]-a[j]);
                if(r%2==0){
                    la+=abs(a[i]-a[j]);
                }else{
                    if(la-abs(a[i]-a[j])>=0)
                        la-=abs(a[i]-a[j]);
                    else
                        la=abs(la-abs(a[i]-a[j]));
                }
            }else if(a[i]==a[j])
                h+=a[i];
            else{
                h+=max(a[i],a[j]);
            }
        }
    }
    cout<<h+la;
}

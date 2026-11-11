#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char c[200005];
int main(){
    cin.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>c[i];
    }
    int i=1,j=n;
    long long sum=0;
    while(i<j){
        if(a[i]>a[j]){
            long long t=a[j];
            a[i]-=a[j];
            a[j]=0;
            if(c[i]!=c[j])
            sum+=t;
            j--;

        }
        else if(a[i]<a[j]){
            long long t=a[i];
            a[j]-=a[i];
            a[i]=0;
            if(c[i]!=c[j])
            sum+=t;
            i++;
        }
        else{
            if(c[i]!=c[j])
            sum+=a[i];
            a[i]=a[j]=0;
            i++;j--;
        }
    }
    cout<<sum<<endl;
    return 0;
}

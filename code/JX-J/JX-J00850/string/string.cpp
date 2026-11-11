#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n,sum=0,s=2;
    cin>>n;
    int a[n];
    char b[n];
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    for(int i=0;i<=n/2;i++){
        if(a[i]>=a[n-i-1] and b[i]!=b[n-i-1]){
            a[i]=a[i]-a[n-i-1];
            sum+=a[n-i-1];
            a[n-i-1]=0;
            b[n-a-1]=b[i];
            while(a[i]>0 and n-i-s>i){
                if(b[i]!=b[n-i-s] and a[i]>a[n-i-s]){
                    a[i]-=a[n-i-s];
                    sum+=a[n-i-s];
                    a[n-i-s]=0;
                    b[n-i-s]=b[i];
                    s++;
                }
                else if(b[i]!=b[n-i-s] and a[i]<=a[n-i-s]){
                    sum+=a[i];
                    a[n-i-s]-=a[i];
                    s--;
                    a[i]=0;
                }
                else if(b[i]==b[n-i-s] and a[i]>a[n-i-s]){
                    a[i]-=a[n-i-s];
                    a[n-i-s]=0;
                    b[n-i-s]=b[i];
                    s++;
                }
                else{
                    a[n-s-i]-=a[i];
                    s--;
                    a[i]=0;
                }
            }
        }
        else if(a[i]<a[n-i-1] and b[i]!=b[n-i-1]){
            sum+=a[i];
            a[n-i-1]-=a[i];
        }
        else if(a[i]>a[n-i-1] and b[i]==b[n-i-1]){
            a[i]=a[i]-a[n-i-1];
            a[n-i-1]=0;
        }
        else{
            a[n-i-1]-=a[i];
            a[i]=0;
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

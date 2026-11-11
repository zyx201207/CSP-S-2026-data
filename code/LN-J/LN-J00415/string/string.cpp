#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin>>n;
    int a[200005]={0};
    char b[200005]={0};
    long long ss=0;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        ss+=a[i];
    }int i=0,j=n+1;
    long long s1=0,s2=0,sum=0;
    while(1){
        if(s1>=s2){
            s1-=s2;
            s2=0;
            j--;
            if(s1>=a[j]&&b[i]!=b[j])sum+=a[j];
            else if(s1<a[j]&&b[i]!=b[j])sum+=s1;
            s2+=a[j];
        }else{
            s2-=s1;
            s1=0;
            i++;
            if(s2>=a[i]&&b[i]!=b[j])sum+=a[i];
            else if(s2<a[i]&&b[i]!=b[j])sum+=s2;
            s1+=a[i];
        }if(i==n&&j==1){
            cout<<sum/2;
            return 0;
        }
    }
    return 0;
}

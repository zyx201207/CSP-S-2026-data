#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    long long n,m,ans=1,mid=0,become=0,soin=0;
    bool flag=true;
    cin>>n>>m;
    long long a[n];
    for(long long q=0;q<n;q++){
        cin>>a[q];
        mid+=a[q];
    }
    mid+=m;
    mid=floor(mid/n);
    sort(a,a+n);
    for(long long i=n;i>0;i--){
        if(a[i]-mid<=0 && flag==true){
            flag=false;
            become=a[i];
            soin=i;
            break;
        }
    }
    long long w=soin,e=become;
    for(long long j=w;j>0;j--){
        m=m-e+a[j];
        if(m>=0){
            ans++;
        }else{
            break;
        }
    }
    cout<< ans;
	return 0;
} 

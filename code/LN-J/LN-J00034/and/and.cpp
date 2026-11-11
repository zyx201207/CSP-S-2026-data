#include<bits/stdc++.h>
using namespace std;
long long n,m,f,aa=1,c=1,ma,ab,ans,nn,mm=pow(2,20)-1,a[100200],b[33],bb[33],bbb[33],cc[5];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    for(int i=0;i<=30;i++) bb[i]=pow(2,i);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        ma=max(ma,a[i]);
        mm&=a[i];
        for(int j=0;j<=30;j++){
            if(a[i]+1==bb[j]) f=0,bbb[j]++;
        }if(f) aa=0;
        f=1;
        if(a[i]>=4) c=0;
        for(int j=30;j>=1;j--) if(a[i]/pow(2,j)!=a[i]/pow(2,j)/2*2) b[j]++;
    }if(m==1) cout<<ma;
    if(m==n) cout<<mm;
    ma=0;
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++) ma=max(ma,a[i]&a[j]);
        }cout<<ma;
    }if(m==n-1){
        for(int i=1;i<=30;i++) if(b[i]==1) nn=i;
        if(nn==0) cout<<0;
        else{
            for(int j=1;j<=n;j++){
                if(a[j]/pow(2,nn)!=a[j]/pow(2,nn)/2*2){
                    for(int i=nn;i>=1;i--) if(b[i]==1&&a[j]/pow(2,i)!=a[j]/pow(2,i)/2*2) ans+=pow(2,i);
                }
            }cout<<ans;
        }
    }if(aa){
        for(int i=30;i>=1;i--){
            ab+=bbb[i];
            if(ab>=m){
                cout<<pow(2,i)-1;
                break;
            }
        }
    }if(c){
        for(int i=1;i<=n;i++) cc[a[i]]++;
        if(cc[3]>=m) cout<<"3";
        else if(cc[3]+cc[2]>=m) cout<<"2";
        else if(cc[3]+cc[2]+cc[1]>=m) cout<<"1";
        else cout<<"0";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

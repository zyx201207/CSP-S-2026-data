#include<bits/stdc++.h>
using namespace std;
long long a,b,c[200005],d[200005],f[200005],g[200005],maxj=0,z[200005],x[200005],cnt=0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>a>>b;
    for(int i=1;i<=a;i++){
        cin>>c[i];
    }
    sort(c,c+a+1);
    int k=1;
    for(int i=a;i>=b;i--){
        d[k]=c[i];
        k++;
    }
    long long j=1;
    for(int i=1;i<=k-1;i++){
        int sum=d[i];
        j=1;
        while(sum>0){
            f[j]=sum%2;
            sum=sum/2;
            j++;
        }
        maxj=max(maxj,j);
    }
    for(int i=1;i<=k-1;i++){
        cnt=0;
        for(int m=1;m<=maxj;m++){
            f[i]=0;
        }
        int sum=d[i];
        j=1;
        while(sum>0){
            f[j]=sum%2;
            sum=sum/2;
            j++;
        }
        for(int m=1;m<=maxj-j+1;m++){
            g[m]=10086;
        }
        for(int m=maxj-j+1;m<=j-1;m++){
            g[m]=f[m];
        }
        if(i==1){
            for(int m=1;m<=maxj-1;m++){
                z[m]=g[m];
            }
        }else{
            for(int m=1;m<=maxj-1;m++){
                    //cout<<g[m]<<" ";
                if(z[m]==0||g[m]==0){
                    z[m]=0;
                }
                if(g[m]==10086){
                    z[m]=10086;
                    cnt++;
                }
            }
        }
    }
    long long sum=1,ans=0;
    for(int i=maxj-cnt-2;i>=1;i--){
        sum*=2;
    }
    //cout<<cnt<<" "<<sum<<" "<<maxj-1<<endl;
    for(int i=maxj-1;i>=1;i--){
        if(z[i]==10086){
            continue;
        }
        //cout<<z[i]<<" "<<sum<<endl;
        if(i==1&&z[i]==1){
            ans++;
            continue;
        }
        if(z[i]==1){
            ans=ans+sum;
        }
        sum=sum/2;
    }
    cout<<ans;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n,m[200005],mid,a[200005],k,s;
char c[200005];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    int cnt=0;
    for(int i=1;i<=n;i++){
        cin>>m[i]>>c[i];
        mid+=m[i];
    }
    if(mid%2==0){
        mid/=2;
        for(int i=1;i<=n;i++){
            a[i]=a[i-1]+m[i];
            if(a[i]==mid){
                k=i;
                break;
            }
            else if(a[i]>mid){
                k=i;
                for(int j=n+1;j>i+1;j--){
                    m[j]=m[j-1];
                    c[j]=c[j-1];
                }
                c[i+1]=c[i];
                m[i+1]=a[i]-mid;
                m[i]-=a[i]-mid;
                n++;
                break;
            }
        }
        for(int i=1;i<=k;i++){
            if(m[i]==m[n-cnt]){
                if(c[i]!=c[n-cnt])s+=m[i];
                cnt++;
            }
            else if(m[i]>m[n-cnt]){
                while(m[i]>=m[n-cnt]){
                    if(c[i]!=c[n-cnt])s+=m[n-cnt];
                    m[i]-=m[n-cnt];
                    cnt++;
                }
                m[n-cnt]-=m[i];
                if(c[i]!=c[n-cnt])s+=m[i];
            }
            else if(m[i]<m[n-cnt]){
                m[n-cnt]-=m[i];
                if(c[i]!=c[n-cnt])s+=m[i];
            }
        }
    }
    else{
        mid/=2;
        for(int i=1;i<=n;i++){
            a[i]=a[i-1]+m[i];
            if(a[i]==mid){
                k=i;
                if(m[i+1]>1)m[i+1]-=1;
                else{
                    for(int j=i+1;j<n;j++){
                        m[j]=m[j+1];
                    }
                    n--;
                }
                break;
            }
            else if(a[i]>mid){
                k=i;
                if(a[i]-mid==1){
                    m[i]--;
                    break;
                }
                m[i]--;
                for(int j=n+1;j>i+1;j--){
                    m[j]=m[j-1];
                    c[j]=c[j-1];
                }
                c[i+1]=c[i];
                m[i+1]=a[i]-mid;
                m[i]-=a[i]-mid;
                n++;
                break;
            }
        }
        for(int i=1;i<=k;i++){
            if(m[i]==m[n-cnt]){
                if(c[i]!=c[n-cnt])s+=m[i];
                cnt++;
            }
            else if(m[i]>m[n-cnt]){
                while(m[i]>=m[n-cnt]){
                    if(c[i]!=c[n-cnt])s+=m[n-cnt];
                    m[i]-=m[n-cnt];
                    cnt++;
                }
                m[n-cnt]-=m[i];
                if(c[i]!=c[n-cnt])s+=m[i];
            }
            else if(m[i]<m[n-cnt]){
                m[n-cnt]-=m[i];
                if(c[i]!=c[n-cnt])s+=m[i];
            }
        }
    }
    cout<<s;
return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+10;
int n,a[N],s[N];
ll ans=0;
int m[1000005];
ll sum=0;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin.tie(nullptr);ios::sync_with_stdio(0);
    cin>>n;int ma=-1;
    for(int i=0;i<n;i++){
        char c;
        cin>>a[i]>>c;
        ma=max(ma,a[i]);
        s[i]=c-'a';
        //cout<<s[i]<<endl;
    }
    if(n<=2000&&ma<=50){
        int id=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
            for(int j=0;j<a[i];j++){
                m[id++]=s[i];
            }
        }
        for(int i=0;i<sum/2;i++){
            if(m[i]!=m[sum-i-1]){
                ans++;
            }
        }
        cout<<ans;
        return 0;

    }
    ll l=0,r=0;int i=0,j=n-1;
    while(i<=j){
        //cout<<i<<' '<<j<<' '<<l<<' '<<r<<endl;
        if(s[i]==s[j]){
            
            if(a[i]-l>a[j]-r){
                    
                l+=a[j]-r;
                r=0;
                    
                j--;

            }else if(a[i]-l<a[j]-r){
                    
                r+=a[i]-l;
                l=0;
                i++;
            }else{
                    
                l=r=0;
                i++;
                j--;
            }
        }else{
            
            
                ans+=min(a[i]-l,a[j]+r);
                
                if(a[i]-l>a[j]-r){
                    
                    l+=a[j]-r;
                    r=0;
                    
                    j--;//cout<<114<<' ';

                }else if(a[i]-l<a[j]-r){
                    
                    r+=a[i]-l;
                    l=0;
                    i++;
                }else{
                    
                    l=r=0;
                    i++;
                    j--;
                }
            
        }
        
    }cout<<ans;
}
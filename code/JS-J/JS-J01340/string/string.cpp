#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char ch[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    
	cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i]>>ch[i];
    }
    long long ans=0;
    for(int i=1; i<=n/2; i++){
        if(a[i]==a[n+1-i]){
            if(ch[i]!=ch[n-i+1]){
                ans+=a[i];
            }
        }
        else if(a[i]!=a[n+1-i]){
            if(ch[i]==ch[n+1-i]){
                if(i+1==n+1-i){
                    continue;
                }
                else{
                    ans=ans+2*(abs(a[i]-a[n-i+1]));
                }
            }
            else if(ch[i]!=ch[n+1-i]){
                if(i+1==n+1-i){
                    ans+=min(a[i],a[n+1-i]);
                }
                else{
                    int dif=abs(a[i]-a[n+1-i]);
                    if(a[i]<a[n+1-i]){
                        a[n+1-i]=a[n+1-i]-dif;
                        a[n+1-i-1]=a[n+1-i-1]+dif;
                        if(a[n+1-i]!=a[n+1-i-1]){
                            ans+=2*dif;   
                        }
                    }
                    else if(a[i]>a[n+1-i]){
                        a[i]=a[i]-dif;
                        a[i+1]=a[i+1]+dif;
                        if(a[i]!=a[i+1]){
                            ans+=2*dif;
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}

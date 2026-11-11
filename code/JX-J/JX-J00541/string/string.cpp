#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans;
int a[300005],b[300005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        char op;
        cin>>op;
        b[i]=(int)(op-'a');
    }
    int j=n;
    for(int i=1;i<=n;i++){
        while(a[i]!=0){
            if(i==j)break;
            if(b[i]!=b[j]){
                if(a[i]>=a[j]){
                    a[i]-=a[j];
                    ans+=a[j];
                    a[j]=0;
                    j--;
                }
                else{
                    a[j]-=a[i];
                    ans+=a[i];
                    a[i]=0;
                    if(a[j]==0)j--;
                }
            }
            else{
                if(a[i]>=a[j]){
                    a[i]-=a[j];
                    a[j]=0;
                    j--;
                }
                else{
                    a[j]-=a[i];
                    a[i]=0;
                    if(a[j]==0)j--;
                }
            }
        }
    }
    cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[300003];
char b[300003];
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,cnt=0,kp=0,lp=0,mark=0;
	cin>>n;
	long long k=n;
	for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        kp+=a[i];
	}

	for(int i=1;i<=n;i++){
        lp+=a[i];
        if(lp>kp/2){
            if(lp-a[i]<kp/2){
                a[i]-=(min(lp-kp/2,kp/2-lp+a[i]))*2;
            }
            mark=i;
            break;
        }
	}
    for(int i=1;i<=mark;i++){
        if(a[i]>=a[k]){
            while(a[i]>=a[k] && k>=mark && a[i]!=0 && i!=k){
                if(b[i]!=b[k]){
                    cnt+=a[k];
                    a[i]-=a[k];
                    k--;
                }else{
                    a[i]-=a[k];
                    k--;
                }
            }
        }
        if(a[i]<=a[k] && k>=mark && a[k]!=0 && i!=k){
            if(b[i]!=b[k]){
                cnt+=a[i];
                a[k]-=a[i];
            }else{
                a[k]-=a[i];
            }
        }
    }
    cout<<cnt+a[mark]/2;
}

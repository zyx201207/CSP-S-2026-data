#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
constexpr int MAXN=5e5+5;
int n;
long long m,a[MAXN],b1[MAXN],c1[MAXN],b2[MAXN],c2[MAXN],sum1,sum2,ans1,ans2;
void YKR(){
    b1[n]=n;
    for(int i=n-1;i>=1;i--){
        if(a[i]==a[i+1]){
            b1[i]=b1[i+1];
        }else{
            b1[i]=i;
        }
    }
}
void NVN(){
    b2[1]=1;
    for(int i=2;i<=n;i++){
        if(a[i]==a[i-1]){
            b2[i]=b2[i-1];
        }else{
            b2[i]=i;
        }
    }
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    YKR();
    NVN();
    for(int i=n;i>=2;i--) c1[i]=a[i]-a[i-1];
    for(int i=2;i<=n;i++) c2[i]=a[i]-a[i+1];
    c1[1]=0;
    c2[n]=0;
    for(int i=1;i<n;i++){
		sum1+=i*c1[i+1];
		if(sum1>m){
			ans1=b1[i];
			break;
		}
    }
    for(int i=n;i>1;i--){
		sum2+=i*c2[i-1];
		if(sum2>m){
			ans2=b2[i];
			break;
		}
    }
    cout<<max(ans1,ans2);
    return 0;
}

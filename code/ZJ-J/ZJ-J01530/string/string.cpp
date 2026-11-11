#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],b[N],sum,sum1,k2=1,k1,ans;
char c[N],d[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		sum1+=a[i];
		if(sum%2==1&&sum1>sum/2){
			k1=i;
			a[i]=sum/2-(sum1-a[i]);
			b[1]=sum1-sum/2-1,d[1]=c[i];
			for(int j=i+1;j<=n;j++){
				b[++k2]=a[j],d[k2]=c[j];
			}
			break;
		}
		else if(sum%2==0&&sum1>=sum/2){
			k1=i;
			a[i]=sum/2-(sum1-a[i]);
			b[1]=sum1-sum/2,d[1]=c[i];
			for(int j=i+1;j<=n;j++){
				b[++k2]=a[j],d[k2]=c[j];
			}
			break;
		}
	}
	int j=1;
	for(int i=1;i<=k1;i++){
		while(a[i]&&j<=k2){
			if(c[i]!=d[j]){
				if(a[i]>=b[j]){
					a[i]-=b[j];
					ans+=b[j];
					b[j]=0;
					j++;
				}
				else b[j]-=a[i],ans+=a[i],a[i]=0;
			}
			else{
				if(a[i]>=b[j]){
					a[i]-=b[j];
					b[j]=0;
					j++;
				}
				else b[j]-=a[i],a[i]=0;
			}
		}
	}
	cout<<ans;
}

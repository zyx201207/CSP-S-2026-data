#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int a[200005],n,ans=0;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int i=1,ai=a[i],ci=c[i],j=n,aj=a[j],cj=c[j];
	while(i!=j){
		if(ci==cj){
			if(ai>aj){
				j--;
				aj=a[j];
				cj=c[j];
				ai-=a[j+1];
			}
			else if(ai<aj){
				i++;
				ai=a[i];
				ci=c[i];
				aj-=a[i-1];
			}
			else{
				i++;
				j--;
				ai=a[i];
				aj=a[j];
				ci=c[i];
				cj=c[j];
			}
		}
		else{
			if(ai>aj){
				j--;
				aj=a[j];
				cj=c[j];
				ai-=a[j+1];
				ans+=a[j+1];
			}
			else if(ai<aj){
				i++;
				ai=a[i];
				ci=c[i];
				aj-=a[i-1];
				ans+=a[i-1];
			}
			else{
				i++;
				j--;
				ai=a[i];
				aj=a[j];
				ci=c[i];
				cj=c[j];
				ans+=a[i-1];
			}
		}
	}
	cout<<ans;
	return 0;
}

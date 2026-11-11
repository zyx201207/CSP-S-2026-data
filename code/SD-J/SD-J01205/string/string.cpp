#include <bits/stdc++.h>
using namespace std;
const int M=2e5;
long long n,a[M+5];
char c[M+5];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
//	long long sum=0;
	for (int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	//	sum+=a[i];
	}//cout<<sum<<endl;
	long long l=a[1],r=a[n],i=1,j=n;
	long long ans=0;
	if (c[1]!=c[n]){
		ans=min(a[1],a[n]);
	}// cout<<ans<<endl;cout<<i<<" "<<l<<"  "<<j<<" "<<r<<"  "<<ans<<endl;
	while (i<j){
		if (l==r){
			i++;
			l+=a[i];
		}
		else if (l<r){
			i++;
			l+=a[i];
			if (c[i]!=c[j]){
				if (l<r){
					ans+=a[i];
				}
				else ans+=r-(l-a[i]); 
			}
		}
		else if (l>r){
			j--;
			r+=a[j];
			if (c[i]!=c[j]){
				if (l>r){
					ans+=a[j];
				}
				else ans+=l-(r-a[j]);
			}
		}//cout<<i<<" "<<l<<"  "<<j<<" "<<r<<"  "<<ans<<endl;
	}
	cout<<ans<<endl;
	return 0;
}

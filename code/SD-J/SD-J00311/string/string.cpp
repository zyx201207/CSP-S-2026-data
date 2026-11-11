#include <bits/stdc++.h>
#define int long long
using namespace std;

long long a[200005],b[200005];
char s[200005],v[200005];

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	
	for(int i=n;i>=1;i--){
		v[n-i+1]=s[i];
		b[n-i+1]=a[i];
	}
	int l=1,r=1;
	long long cnt=0,k=0;
	char t;
	int z=0;
	while(l<=n&&r<=n){
		
		while(k!=0){
			//cout<<l<<' '<<r<<' '<<t<<' '<<k<<' '<<z<<endl;
			if(z==1){
				if(t==v[r]){
					if(b[r]>=k){
						b[r]-=k;
						k=0;
						z=0;
						t=v[r];
						continue;
					}
					else{
						k-=b[r];
						r++;
						continue;
					}
				}
				else{
					if(b[r]>=k){
						cnt+=k;
						b[r]-=k;
						k=0;
						z=0;
						t=v[r];
					    //cout<<k<<" "<<t<<' '<<z<<' '<<cnt<<endl;
						continue;
					}
					else{
						cnt+=b[r];
						k-=b[r];
						r++;
						continue;
					}
				}
			}
			
			else{
				if(t==s[l]){
					if(a[l]>=k){
						a[l]-=k;
						k=0;
						z=1;
						t=s[l];
						continue;
					}
					else{
						k-=a[l];
						l++;
						continue;
					}
				}
				else{
					if(a[l]>=k){
						cnt+=k;
						a[l]-=k;
						k=0;
						z=1;
						t=s[l];
						continue;
					}
					else{
						cnt+=a[l];
						k-=a[l];
						l++;
						continue;
					}
				}
			}
		}
		
		if(s[l]==v[r]){
			if(a[l]>b[r]){
				k=a[l]-b[r];
				t=s[l];
				z=1;
				l++,r++;
				//cout<<l<<" "<<r<<' '<<k<<" "<<t<<' '<<z<<' '<<cnt<<endl;
				continue;
			}
			else {
				t=v[r];
				k=b[r]-a[l];
				z=0;
				l++,r++;
				continue;
			}
		}
		
		if(s[l]!=v[r]){
			if(a[l]>b[r]){
				cnt+=b[r];
				k=a[l]-b[r];
				t=s[l];
				z=1;
				l++,r++;
				//cout<<l<<" "<<r<<' '<<k<<" "<<t<<' '<<z<<' '<<cnt<<endl;
				continue;
			}
			else {
				cnt+=a[l];
				k=b[r]-a[l];
				t=v[r];
				z=0;
				l++,r++;
				//cout<<l<<" "<<r<<' '<<k<<" "<<t<<' '<<z<<' '<<cnt<<endl;
				continue;
			}
		}
	}
	cout<<cnt/2;
	return 0;
}

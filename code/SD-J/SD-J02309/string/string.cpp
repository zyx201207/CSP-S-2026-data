#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
long long l_c,r_c,l,ans;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	int l_t=0,r_t=n+1;
	for(long long i=1;i<=l/2;i++){
		long long f=0;
		if(l_c<i){
			l_t++;
			l_c+=a[l_t];
			f=1;
		}
		if(r_c<i){
			r_t--;
			r_c+=a[r_t];
			f=1;
		}
		if(c[l_t]!=c[r_t]){
			if(l_c-i+1<=r_c-i+1){
				f=l_c-i+1;
				i=l_c;
			}else{
				f=r_c-i+1;
				i=r_c;
			}
			ans+=f;
		}
//		cout<<"L:"<<l_t<<" "<<c[l_t]<<"  R:"<<r_t<<" "<<c[r_t]<<" ans:"<<ans<<"\n";
	}
	cout<<ans;
	return 0;
}

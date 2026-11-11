//Kong Chenfeng xi'an shi han guang zhong xue SN-J00666
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int maxn=2e5+5;
int a[maxn];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n,len=0;
	ll ans=0;
	string s;
	cin>>n;
	while(n--){
		int cnt;
		char c;
		cin>>cnt>>c;
		s+=c; 
		a[len++]=cnt;
	}
	for(int i=0,j=len-1;i<len/2&&j>len/2;){
		if(s[i]!=s[j]){
			if(a[i]>a[j]){
				ans+=a[j];
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				ans+=a[i];
				a[j]-=a[i];
				i++; 
			}else{
				ans+=a[i];
				i++,j--;
			}
		}else{
			if(a[i]>a[j]){
				a[i]-=a[j];
				j--;
			}else if(a[i]<a[j]){
				a[j]-=a[i];
				i++;
			}else{
				i++,j--;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}


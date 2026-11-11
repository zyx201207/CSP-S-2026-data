#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,a[N],sum,len,ans;
char c[N];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		if(sum<1e6) sum+=a[i];
	}
	if(sum<=1e6){
		for(int i=1;i<=n;i++) while(a[i]--) s+=c[i];
		len=s.size();
		for(int i=0;i<=len/2;i++) ans+=(s[i]!=s[len-i-1]);
		cout<<ans;
		return 0;
	}
	for(int l=1,r=n,suml=a[1],sumr=a[n];l<r;){
		if(suml<=sumr){
			ans+=(suml-sumr+a[r])*(c[l]!=c[r]);
			l++;
			suml+=a[l];
			sumr+=a[l];
		}
		else{
			ans+=(sumr-suml+a[l])*(c[l]!=c[r]);
			r--;
			suml+=a[r];
			sumr+=a[r];
		}
	}
	cout<<ans;
	return 0;
}

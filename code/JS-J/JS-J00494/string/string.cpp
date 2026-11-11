#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
long long n,a[maxn],b[maxn],sum,ans;
string s;
char c[maxn];
bool flag;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	cin>>a[1]>>c[1];
	sum+=a[1];
	b[1]=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=a[i];
		if(c[i]!=c[i-1])flag=true;
	}
	if(!flag||n==1){
		cout<<0;
		return 0;
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]){
			if(b[l]<b[r]){
				ans+=b[l];
				b[r]-=b[l++];
			}else if(b[l]>b[r]){
				ans+=b[r];
				b[l]-=b[r--];
			}else if(b[l]==b[r]){
				ans+=b[l];
				l++,r--;
			}
		}else{
			if(b[l]<b[r])b[r]-=b[l++];
			else if(b[l]>b[r])b[l]-=b[r--];
			else if(b[l]==b[r])l++,r--;
		}
	}
	cout<<ans;
	return 0;
}



#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int n,a[N],cnt,l,r,sum;
char s[N],c;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	l=1;
	r=n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	while(l<=r){
		if(s[l]==s[r]){
			if(a[l]>a[r]){
				a[l]-=a[r];
				r--;
			}
			else{
				a[r]-=a[l];
				l++;
			}
		}
		else{
			if(a[l]>a[r]){
				sum+=a[r];
				a[l]-=a[r];
				r--;
			}
			else{
				sum+=a[l];
				a[r]-=a[l];
				l++;
			}
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

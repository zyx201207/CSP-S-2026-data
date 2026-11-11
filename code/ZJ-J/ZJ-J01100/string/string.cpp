#include<bits/stdc++.h>
using namespace std;
int n;
const int N=2e5+5;
long long a[N];
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	if(n<=1){
		cout<<0;
		return 0;
	}
	int l=1,r=n;
	long long suml=a[l],sumr=a[n];
	long long ans=0;
	if(s[l]!=s[r]){
		ans+=min(suml,sumr);
	}
	if(n==2){
		cout<<ans;
		return 0;
	}
	while(l<r){
		if(suml<=sumr){
			l++;
			if(l==r)break;
			long long sum=suml+a[l];
			if(s[l]!=s[r]){
				ans+=min(a[l],sumr-suml);
			}
			suml=sum;
		}else if(suml>sumr){
			r--;
			if(l==r)break;
			long long sum=sumr+a[r];
			if(s[l]!=s[r]){
				ans+=min(a[r],suml-sumr);
			}
			sumr=sum;
		}
	}
	cout<<ans;
	return 0;
}

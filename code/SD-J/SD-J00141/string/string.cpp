#include<bits/stdc++.h>
using namespace std;
int n;
char c[200002];
string s;
long long int a[200002],cnt,maxn,len;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	bool f=1;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];++j){
			s[j]=c[i];
		}
		if(i>1){
			if(c[i]!=c[i-1]){
				f=0;
			}
		}
		len+=a[i];
	}
	if(f==1){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=len/2;++i){
		if(s[i]!=s[len-i+1])cnt++;
	}
//	int r=n;
//	int l=1;
//	while(l<r){
//		if(c[l]==c[r]){
//			if(a[l]!=a[r]&&abs(r-l)!=1){
//				cnt+=abs(a[r]-a[l]);
//			}
//		}
//		else{
//			cnt=cnt+min(a[l],a[r]);
//		}
//		l++;
//		r--;
//	}
//	if(n%2==1)cnt+=a[n/2+1]/2;
	cout<<cnt;
	return 0;
}
/*
3
2 a
2 b
1 c

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

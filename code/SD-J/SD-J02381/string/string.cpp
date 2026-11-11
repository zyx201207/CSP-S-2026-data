#include<bits/stdc++.h>
using namespace std;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=0;
	long long m=0,l=0,r;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		long long a;
		char c;
		scanf("%lld %c",&a,&c);
		m+=a;
		while(a--){
			s+=c;
		}
	}
	r=m-1;
	char a1,a2;
	while(r>l){
		a1=s[l];
		a2=s[r];
		if(a1!=a2) ans++;
		r--;
		l++;
	}
	printf("%lld",ans);
	return 0;
} 

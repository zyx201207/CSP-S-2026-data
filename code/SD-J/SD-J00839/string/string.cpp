#include<bits/stdc++.h>
using namespace std;
int n;
long long a;
char c;
long long cn;
long long j3,j2;
struct q{
	long long sum;
	char w;
}s[200010];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	j2=n-1;
	for(int i=0;i<n;i++){
		cin>>a>>c;
		cn+=a;
		s[i]={cn,c};
	}
	for(int i=0;i<(s[n-1].sum+1)/2;i++){
	//	cout<<i<<'\n';
		char a1,b1;
		if(i<s[j3].sum){
			a1=s[j3].w;
		}else{
			j3++;
			a1=s[j3].w;
		}if(s[n-1].sum-i-1>=s[j2].sum){
			b1=s[j2+1].w;
		}else{
			b1=s[j2].w;
			j2--;
		}
		//cout<<a1<<b1;
		if(a1!=b1){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}


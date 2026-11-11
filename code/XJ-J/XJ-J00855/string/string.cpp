#include <bits/stdc++.h>
using namespace std;
long long sum,n,a,gai;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a;
		cin>>c;
		for(int i=0;i<a;i++){
			s+=c;
		}
		sum+=a;
	}
	for(long long j=0;j<(sum-1)/2;j++){
		long long i=sum-1-j;
		if(s[i]!=s[j]){
			gai++;
		}
	}
	cout<<gai;
	return 0;
}

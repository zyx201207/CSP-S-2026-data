#include<bits/stdc++.h>
using namespace std;
long long n,num,ans;
char c;
string a,q;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	a="x";
	long long st=0;
	for(long long i=1;i<=n;i++){
		cin>>num>>c;

		for(long long j=1;j<=num;j++){
			a+=c;
		}
		st+=num;
	}//CIN-END
	for(long long i=1;i<=st/2;i++){
		if(a[i]!=a[st-i+1])ans++;
	}
	cout<<ans;
	
	return 0;
}

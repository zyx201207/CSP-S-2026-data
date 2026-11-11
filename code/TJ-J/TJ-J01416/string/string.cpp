#include<bits/stdc++.h>
using namespace std;
string ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,a,maxx=-1,sum=0;
	string b,anr;
	cin >> n;
	for(long long i=1;i<=n;i++){
		cin >> a >> b;
		if(maxx<=a){
			maxx==a;
			anr=b;
		}
		for(int j=1;j<=a;j++){
			ans+=b;
		}
	}
	int r=ans.size();
	for(long long i=0;i<r/2;i++){
		if(ans[i]!=ans[r-1]){
			if(ans[i]==anr[0]){
				ans[i]=anr[0];
			}
			else{
				ans[i]=ans[r-1];
			}
			sum++;
		}
	}
	cout << sum;
	return 0;
}

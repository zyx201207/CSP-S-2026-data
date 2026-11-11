#include <bits/stdc++.h>
using namespace std;
string num,s,tum,zum,sum;
long long x,t,mid,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>x>>s;
		for (int j=1;j<=x;j++){
			num+=s;
			t++;
		}
	}
	if (t%2==1){
		mid=t/2+1;
		for (int i=0;i<mid;i++){
			tum+=num[i];
            
		}
		for (int i=mid-2;i>=0;i--){
			zum+=tum[i];			
		}
		sum=tum+zum;
	}
	else{
		mid=t/2;
		for (int i=0;i<mid;i++){
			tum+=num[i];
		}
		for (int i=mid-1;i>=0;i--){
			zum+=tum[i];
		}
		sum=tum+zum;
	}
	for (int i=1;i<=t;i++){
		if (num[i]!=sum[i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
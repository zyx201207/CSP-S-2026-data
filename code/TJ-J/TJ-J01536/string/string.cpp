#include<bits/stdc++.h>
using namespace std;
int n;
string str;
long long sum,cnt,ans; 
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>cnt>>c;
		while(cnt--){
			str[sum]=c;
			sum++;
		}
		cnt=0;
	}
	sum-=1;
	long long s=sum/2;
	for(long long i=sum,j=0;i>=s,j<=s;i--,j++){
		if(str[j]!=str[i]&&i!=j){
			ans++;
		}
	}

	cout<<ans;
	return 0;
}

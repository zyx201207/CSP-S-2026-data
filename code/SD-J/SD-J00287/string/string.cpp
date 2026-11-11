#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],ans,sum;
string s1;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s1+=c[i];
		}
	}
	if(sum%2==1){
		long long num=sum/2;
		for(int i=0;i<num;i++){
			if(s1[i]!=s1[sum-i-1]){
				s1[sum-i-1]=s1[i];
				ans++;
			}
		}
	}
	else{
		long long num=sum/2;
		for(int i=0;i<=num;i++){
			if(s1[i]!=s1[sum-i-1]){
				s1[sum-i-1]=s1[i];
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

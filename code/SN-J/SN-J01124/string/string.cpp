#include<bits/stdc++.h>
using namespace std;
int a[200005],n;
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s=" ";
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
		sum+=a[i];
	}
	int ans=0;
	int ban=sum/2,j=1;
	for(int i=1;i<=ban;i++){
		if(s[i]!=s[sum-i+1]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

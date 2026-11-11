#include<iostream>
using namespace std;
long long n,ans,a[200005];
char ch[200005];
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long cnt=0,sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>ch[i];
		if(ch[i]==ch[i-1]){
			sum++;
		}
	}
	if(sum==n){
		cout<<0<<endl;
	}
	for(long long i=1;i<=n;i++){
		for(long long k=cnt;k<=cnt+a[i]-1;k++){
			s+=ch[i];
		}
		cnt+=a[i];
	}
	for(long long i=0;i<=cnt/2-1;i++){
		if(s[i]!=s[cnt-i-1]){
			//cout<<s[i]<<" "<<s[cnt-i-1]<<endl;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[200005],ans=0;
char c[200005];
string s;
int n;
long long cnt;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i] >> c[i];
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	cnt=s.size()-1;
	for(int i=0;i<=s.size()-1;i++){
		for(int j=cnt;j>=0;j--){
			if(s[i]!=s[j]){
				ans++;
				s[j]=s[i];
			}
			cnt--;
			break;
		}
	}
	printf("%lld\n",ans);
	return 0;
} 

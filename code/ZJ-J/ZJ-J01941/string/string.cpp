#include<bits/stdc++.h>
using namespace std;
int n;
string s;
long long ans,cnt=1,sum;
struct node{
	long long q;
	char w;
}a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i].q>>a[i].w;
	for(int j=1;j<=n;j++){
		for(long long i=cnt;i<cnt+a[j].q;i++) s[i]=a[j].w;
		cnt+=a[j].q;
	}
	for(long long i=1;i<=(cnt)/2;i++){
		if(s[i]!=s[cnt-i]){
			s[cnt-i]=s[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
}       
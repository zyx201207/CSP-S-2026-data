#include<bits/stdc++.h>
using namespace std;
int n,a;
char b,s[200005];
int cnt,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		cin>>b;
		int ab=a+cnt;
		for(int i=cnt+1;i<=ab;i++){
			s[i]=b;
			cnt++;
		}
	}
	int l=1,r=cnt;
	for(int i=1;i<=cnt/2+1;i++){
		if(s[l]==s[r]){
			continue;
			l++;
			r--;
		}
		else{
			ans++;
			s[r]=s[l];
			l++;
			r--;
		}
	}
	cout<<ans<<endl;
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++){
		cout<<s[i];
	}
}

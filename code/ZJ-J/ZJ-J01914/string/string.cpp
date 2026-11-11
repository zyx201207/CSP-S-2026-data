#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,a[N];
char s[N];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a[i]>>s[i];
	}
	int t1=a[1],t2=a[n];
	for(int i=1,j=n;i<j;){
		if(t1<t2){
			if(s[i]!=s[j]){
				ans+=t1;
			}
			t2-=t1;
			++i;
			t1=a[i];
		}
		else if(t1>t2){
			if(s[i]!=s[j]){
				ans+=t2;
			}
			t1-=t2;
			--j;
			t2=a[j];
		}
		else{
			if(s[i]!=s[j]){
				ans+=t1;
			}
			++i;
			--j;
			t1=a[i];
			t2=a[j];
		}
	}
	cout<<ans;
}


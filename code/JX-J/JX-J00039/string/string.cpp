#include <bits/stdc++.h>
using namespace std;

int n;
char s[200005];
long long a[200005],cnt;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>s[i];
	}
	int i=0,j=n-1;
	while(i<j){
		if(a[i]==a[j]){
			if(s[i]!=s[j])cnt+=a[i];
			i++;
			j--;
		}
		while(a[i]>a[j]){
			if(s[i]!=s[j])cnt+=a[j];
			a[i]-=a[j];
			j--;
		}
		while(a[i]<a[j]){
			if(s[i]!=s[j])cnt+=a[i];
			a[j]-=a[i];
			i++;
		}
	}
	cout<<cnt;
	return 0;
}

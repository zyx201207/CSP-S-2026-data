#include<bits/stdc++.h> 
using namespace std;
long long a[200005],n,l,ans,mid,k;
char c[200005];
string s,s1,s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	for(int i=0;i<n;i++){
		l+=a[i];
	}
	mid=l/2+1;
	for(int i=0,j=l-1;i<=mid&&j>=mid;i++,j--){
		if(s[i]!=s[j]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>

using namespace std;
long long a[300001],n,r,l=0,cnt=0;
 string s;
 char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out,"w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	r=s.size()-1;
	while(l<r){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++,r--;
	}
	cout<<cnt;
	return 0;
} 

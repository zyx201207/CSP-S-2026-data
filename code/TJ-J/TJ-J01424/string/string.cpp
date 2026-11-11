#include<bits/stdc++.h>
using namespace std;
int sum,n,a[200005];
string c[200005],s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		string d;
		for(int j=1;j<=a[i];j++){
			d+=c[i];
		}
		s+=d;
	}
	int l=0,r=s.length();
	while(l!=r){
		if(s[l]!=s[r]){
			s[r]=s[l];
			sum++;
		}
		else{
			continue;
		}
		l++;
		r--;
	}
	cout<<sum;
	return 0;
}

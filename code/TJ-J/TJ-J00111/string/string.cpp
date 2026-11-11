#include<bits/stdc++.h>
using namespace std;
string s;
long long a[100005];
string b;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,c=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	int l=0,r=n-1;
	long long cnt=0;
	bool f=0;
	while(l<=r){
		if(b[l]!=b[r]){
			f=1;
		}
		r--;
		l++;
	}
	if (f==0) {
		cout<<0;
	} else {
		for(int i=0;i<n;i++){
			cnt+=a[i]/2;	
		}
		cout<<cnt<<endl;
	}
	return 0;
}


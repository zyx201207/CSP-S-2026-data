#include <bits/stdc++.h>
using namespace std;
const int N=200005;
const long long M=0x3f3f3f;
long long a[N];
long long s[M];
long long f=0;
int main(){
	ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			s[f]=a[i]&a[j];
			f++;
		}
	}
	sort(s,s+f);
	if(m==1){
		cout<<a[n-1];
	}else{
		cout<<s[f-1];
	}
	
	return 0;
}


#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,p,s=1,v=0,m;
	cin>>n>>p;
	long long l[n];
	for(int i=0;i<n;i++){
		cin>>l[i];
	}
	sort(l,l+n);
	m=l[1]-l[0];
	for(int i=0;i<n;i++){
		m=min(m,l[i+1]-l[i]);
	}
	while(true){
		v=v+s;
		if(v>p){
			break;
		}
		s++;
	}
	cout<<s;
	return 0;
}


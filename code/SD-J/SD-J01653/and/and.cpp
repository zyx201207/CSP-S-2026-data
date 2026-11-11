#include<bits/stdc++.h>
using namespace std;
int n,m,s,a[200010];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(m==1){
		cout<<a[n-1];
	}else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				s=max(s,a[i]&a[j]);
			}
		}
		cout<<s;
	}else{
		s=INT_MAX;
		for(int i=n-m;i<n;i++){
			s=s&a[i];
		}
		cout<<s;
	}
	return 0;
}

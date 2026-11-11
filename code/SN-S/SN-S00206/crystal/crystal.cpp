#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("crytal.in","r",stdin);
	freopen("crytal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m;
	long long a[10005];
	cin>>n>>m;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}
	int v=0;
	long long s=0;
	long long min=99999999;
	for(int i=0; i<m; i++) {
		s=0;
		for(int j=0; j<n; j++) {
			if(a[i]>=a[j]) {
				s+=a[i]-a[j];
			} else {
				s+=a[j]-a[i];
			}
		}
		if(s<min) {
			min=s;
			v=i;
		}
	}
	int b[10005];
	for(int i=0; i<n; i++) {
		int x=0;
		if(a[v]>=a[i]) x=a[v]-a[i];
		else x=a[i]-a[v];
		b[i]=x; 
	}
	int h=0;
	sort(b,b+n-1);
	for(int i=0;i<n;i++){
		m-=b[i];
		h++;
		if(m==0&&a[i]!=0){
			cout<<h+1;
			break;
		}else{
			cout<<h+2;
			break;
		}
	}
	return 0;
}

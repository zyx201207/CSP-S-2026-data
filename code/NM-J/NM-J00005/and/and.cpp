#include<bits/stdc++.h> 
using namespace std;
int main(){
	int n,m;
	int s[]={};
	int h[]={};
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			cin>>s[i];
			h[i]=s[i]&s[i+1];
		}
	}
	sort(h,h+n);
	cout<<h[0];
	return 0;
}

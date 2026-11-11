#include<bits/stdc++.h>
using namespace std;
int n,cnt=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int x;char a;
	for(int i=0;i<n;i++){
		scanf("%d %c",&x,&a);
		while(x--){
			s=s+a;
		}
	}
	int l=0,r=s.size()-1;
	while(l!=r&&l<r){
		if(s[l]!=s[r]){
			cnt++;
		}
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
} 

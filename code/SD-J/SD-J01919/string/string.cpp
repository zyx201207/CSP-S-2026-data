#include<bits/stdc++.h>
using namespace std;
struct node{
	int x;
	char ch;
}p[200010]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int w=0;
	string s="";
	for(int i=1;i<=n;i++){
		cin>>p[i].x>>p[i].ch;
		w+=p[i].x;
		for(int j=1;j<=p[i].x;j++){
			s+=p[i].ch;
		} 
	}
	long long ans=0;
	int l=0,r=w-1;
	if(w%2==0){
		while(l<=r){
			if(s[l]!=s[r]){
				ans++;
			}
			l++;
			r--;
		}
	}
	else{
		while(l<r){
			if(s[l]!=s[r]){
				ans++;
			} 
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}

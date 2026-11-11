#include<bits/stdc++.h>
using namespace std;
int n,a;
char c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s1,s2;
	cin>>n;
	int ans;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		sum+=a;
		while(a--){
			s1+=c;
		}
		
	} 
	int r=sum-1;
	int l=0;
	for(int l=0;l<=r;l++){
		if(s1[l]!=s1[r]){
			ans+=1;
		}
		r--;
	}
	cout<<ans;
	return 0;
} 
 

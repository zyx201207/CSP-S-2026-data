#include<bits/stdc++.h>
using namespace std;
const int N=2e5;
struct node{
	int num;
	char c;
};
node a[N];//b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	string s="0";
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].num>>a[i].c;
		for(int j=1;j<=a[i].num;j++) s+=a[i].c;
		
//		b[n-i+1].num=a[i].num;
//		b[n-i+1].c=a[i].c;
	} 
	if(n==1) cout<<0;
	else{
		long long l=s.size()-1;
		int ans=0;
		for(int i=1;i<=l/2;i++){
			if(s[i]!=s[l-i+1]) ans++;
		}
		cout<<ans;
	}
	
	return 0;
} 

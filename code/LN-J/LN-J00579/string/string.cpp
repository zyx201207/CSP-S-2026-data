#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	string s1,s2;
	int n,sum=0,r=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		cin>>x>>y;
		for(int j=r;j<=x+r-1;j++)s1[j]=y;
		r+=x;
	}
	for(int i=1;i<=r/2;i++)
		if(s1[i]!=s1[r-i])sum++;
	cout<<sum;
	cout<<"\n";
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,midd;
int sum,ans;
struct node{
	char i;
	int s;
	int x,y;
}a[200005];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].s>>a[i].i;
		a[i].x=a[i-1].y+1;
		a[i].y=a[i].x+a[i].s-1;
		sum+=a[i].s;
	}
	if(sum<=8e7){
		string s1,s2;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=a[i].s;j++)s+=a[i].i;
		}
		s1=s;
		s2=s;
		if(sum%2){
			midd=sum/2+1;
			s1.erase(midd-1);
			s2.erase(0,midd);
			for(int i=0;i<s1.size();i++)if(s1[i]!=s2[s2.size()-i-1])ans++;
			cout<<ans;
		}
		else{
			midd=sum/2;
			s1.erase(midd);
			s2.erase(0,midd);
			for(int i=0;i<s1.size();i++)if(s1[i]!=s2[i])ans++;
			cout<<ans;
		}
	}
	else cout<<sum/2;
	return 0;
}
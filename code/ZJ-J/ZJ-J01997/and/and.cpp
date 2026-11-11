#include<bits/stdc++.h>
#include<string>
using namespace std;
long long n,m,an[200010],ans;
char c[200010];
string st;
struct node{
	long long x,y;	
}a[200010];
bool cmp(node xx,node yy){
	return xx.y<yy.y;
}
long long tt(long long k){
	int x=0;
	while(k){
		if(k%2)c[++x]='1';
		else c[++x]='0';
		k/=2;
	}
	return x;
}
string two(long long k){
	int x=0;
	while(k){
		if(k%2)c[++x]='1';
		else c[++x]='0';
		k/=2;
	}
	for(int i=x;i>=1;i--){
		st+=c[i];
	}
	return st;
}
long long add(string st1,string st2){
	int x=min(st1.size(),st2.size());
	int ans=0,y=0,s1=st1.size()-1,s2=st2.size()-1;
	for(int i=0;i<x;i++){
		if(st1[s1-i]&&st2[s2-i])an[++y]='1';
		else an[++y]='0';
	}
	for(int j=y;j>=1;j--){
		int t=1;
		ans+=t*an[j];
		t*=2;
	}
	return ans;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].x;
		a[i].y=tt(a[i].x);
	}
	sort(a+1,a+n+1,cmp);
	ans=a[n].x;
	for(int i=n-1;i>=n-m+1;i--){
			ans=add(two(ans),two(a[i].x));
		}	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}              
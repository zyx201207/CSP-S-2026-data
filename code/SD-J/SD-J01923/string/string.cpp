#include<bits/stdc++.h>
using namespace std;
int n,a[200001];
long long s;
char c[200001];
string t;
bool b,d,e;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;}
	if(n==2){
		scanf("%d %c",&a[0],&c[0]);
		scanf("%d %c",&a[1],&c[1]);
		for(int i=0;i<a[0];i++)	t+=c[0];
		for(int i=0;i<a[1];i++)	t+=c[1];
		for(int i=0;i<t.size()/2;i++)	if(t[i]!=t[t.size()-i-1])	s++;
		cout<<s;
		return 0;}
	for(int i=0;i<n;i++){
		scanf("%d %c",&a[i],&c[i]);
		if(a[i]!=1)	e=1;
		else	t+=c[i];
		if(i==0)	continue;
		if(c[i]!=c[i-1])	b=1;
		if(a[i]!=a[i-1])	d=1;
	}
	if(!b){
		cout<<0;
		return 0;}
	if(!d){
		for(int i=0;i<n/2;i++)	if(c[i]!=c[n-i-1])	s+=a[i];
		cout<<s;
		return 0;}
		t="";
	for(int i=0;i<n;i++)	for(int j=0;j<a[i];j++)	t+=c[i];
	for(int i=0;i<=t.size()/2;i++)	if(t[i]!=t[t.size()-i-1])	s++;
	cout<<s;
	return 0;
}


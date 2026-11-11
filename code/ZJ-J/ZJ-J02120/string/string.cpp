#include<bits/stdc++.h>
using namespace std;
int n,a[200004]={0},b=0;
long long l=0;
char c[200004]={};
int find(int e){
	long long f=0;
	for(int i=0;i<n;i++){
		f+=a[i];
		if(e<f)return i;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		l+=a[i];
	}
	for(int i=0;i*2+1<l;i++)b+=(c[find(i)]!=c[find(l-1-i)]);
	cout<<b;
	fclose(stdin);
	fclose(stdout);
}
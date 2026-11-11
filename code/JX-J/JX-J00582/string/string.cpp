#include<bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
bool dp;	
string s,s2;
long long o=1,sum;
int main(){
	freopen("string.in",'r',stdin);
	freopen("string.out",'w',stdout);
	int n,minx=1e9;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		if(a[i]<=minx)minx=a[i];
	}
	for(int i=minx;i>=2;i--){
		for(int j=1;j<=n;j++){
				if(a[j]%i!=0){
					dp=1;
				}
		}
		if(dp==0){
			o=i;
			for(int j=1;j<=n;j++){
				a[j]/=i;
			}
			break;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=b[i];
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=a[i];j++){
				s2+=b[i];
			}
	}
	for(int i=0;i<s.size();i++){
		if(s2[i]!=s[i]){
			sum++;
			s2[i]=s[i];
		}
	}
	cout<<(sum*o+1)/2;
	return 0;
}

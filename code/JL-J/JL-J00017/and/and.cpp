#include <bits/stdc++.h>
using namespace std;
const int N=2e5;
int a[N],n,m,maxn=0,max2n=0;
string turn(int s){
	string s1;
	while(s){
		char ss=(char)s%2+48;
		s1=ss+s1;
		s/=2;
	}
	return s1;
}
int t1(int a,int b){
	string s1=turn(a);
	string s2=turn(b),ans={};
	int ans1=0;
	int len1=s2.size(),len2=s1.size();
	if(s1.size()<s2.size()){
		for(int i=0;i<=len1-len2-1;i++){
			s1='2'+s1;
		}
	}
	if(s2.size()<s1.size()){
		for(int i=0;i<=len2-len1-1;i++){
			s1='2'+s1;
		}
	}
	for(int i=max(len1,len2)-1;i>=0;i--){
		if(s1[i]==s2[i]){
			ans='1'+ans;
		}
		if(s1[i]!=s2[i]){
			if(s1[i]=='2'){
				ans=s2[i]+ans;
				continue;
			}
			if(s2[i]=='2'){
				ans=s1[i]+ans;
				continue;
			}
			ans='0'+ans;
		}
	}
	int len=ans.size()-1;
	for(int i=len;i>=0;i--){
		if(ans[i]=='1'){
			ans1+=pow(2,len-i);
		}
	}
	return ans1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=0;i<n;i++){
		cin >> a[i];
		maxn=max(maxn,a[i]);
		if(a[i]!=maxn){
			max2n=max(max2n,a[i]);
		}
	}
	if(m==1){
		cout << maxn;
	} 
	if(m==2){
		cout << t1(maxn,max2n);
	}
	if(m==n){
		int num=0;
		for(int i=0;i<n;i++){
			num=t1(num,a[i]);
		}
		cout << num;
	}
	return 0;
}

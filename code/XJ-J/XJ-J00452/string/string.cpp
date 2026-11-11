#include<bits/stdc++.h>
using namespace std;
long long n;
struct node{
	long long sss;
	char c;
}a[20010];

bool sh(string str){
	long long s=str.size();
	while(s--){
		long long l=1,r=s;
		if(str[l]!=str[r]){
			return false;
		}
		l++;
		r--;
	}
	return true;
}
int main(){
	cin>>n;
	string s1="";
	for(int i=1;i<=n;i++){
		cin>>a[i].sss>>a[i].c;
		s1+=a[i].c;
	}
	long long ans=0;
	for(int i=n;i>=1;i--){
		if(sh(s1)){
			continue;
		}else{
			ans+=a[i].sss;
			if(i==n>>1+1&&!(i%2==0)){
				ans-=1;
			}
			a[i].c==a[n-i+1].c;
		}
	}
	cout<<ans;
	return 0;
}

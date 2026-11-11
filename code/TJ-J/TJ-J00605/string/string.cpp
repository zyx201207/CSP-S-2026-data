#include<bits/stdc++.h>
using namespace std;
bool huiwenshu(string s){
	int l=s.size();
	string b;
	for(int i=1;i<=l;i++){
		b[i]=s[l-i];
	}
	bool flag=1;
	for(int i=1;i<=l;i++){
		if(s[i]!=b[i]){
			flag=0;
		}
	}
	return flag;
}
char tj[1001];
int panduan(string s){
	int a[10001];
	int ans;
	int sum=0;
	int l=s.size();
	for(int i=1;i<=l/2;i++){
		s[i]=tj[i];
		ans++;
		if(huiwenshu(s)==1){
			a[sum]=ans;
			ans=0;
		}else{
			continue;
		}
		for(int j=l;j>l/2;j--){
			s[i]=tj[j];
			ans++;
			if(huiwenshu(s)==1){
				a[sum]=ans;
				ans=0;
				sum++;
			}else{
				continue;
			}
		}
	}
	int min=100000000;
	for(int i=1;i<=sum;i++){
		if(a[i]<=min){
			min=a[i];
		}
	}
	return min;
}
int main(){
	//freopen("string.in","r",stdin);
	//freopen("string.out","w",stdout);
	int n;
	int m;
	char a;
	cin>>n;
	int sum=1;
	string s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin>>m;
		cin>>a;
		tj[cnt]=a;
		cnt++;
		for(int i=sum;i<=sum+m;i++){
			s[i]=a;
		}
		sum+=m;
	}
	if(huiwenshu(s)==1){
		cout<<0;
	}else{
		cout<<panduan(s);
	}
	return 0;
}

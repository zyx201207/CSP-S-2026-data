#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		int a;
		string s;
		cin>>a>>s;
		cout<<'0';
		return 0;
	}
	if(n==2){
		int a,b;
		string s1,s2;
		cin>>a>>s1>>b>>s2;
		if(s1!=s2){
			cout<<abs(a-b);
		}else{
			cout<<"0";
		}
		return 0;
	}if(n<=10){
		int a[15];
		char b[15];
		char c[505];
		int t;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
			t+=a[i];
			for(int j=1;j<=a[i];j++){
				c[j]=b[i];
			}
		}
		int sum=0;
		for(int i=1,j=t;i<=j;i++,j--){
			if(c[i]!=c[j])sum++;
		}
		cout<<sum;
		return 0;
	}else{
		int a[2005];
		char b[2005];
		char c[100005];
		int t;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i];
			t+=a[i];
			for(int j=1;j<=a[i];j++){
				c[j]=b[i];
			}
		}
		int sum=0;
		for(int i=1,j=t;i<=j;i++,j--){
			if(c[i]!=c[j])sum++;
		}
		cout<<sum;
		return 0;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

struct st{
	int x;
	char y;
}a[200005];
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int m=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		m+=a[i].x;
	}
	char s[m+5];
	char s1[m/2+10];
	char s2[m/2+10];
	if(n==1){
		cout<<0;
		return 0;
	}
	if(n==2&&a[1].y==a[2].y){
		cout<<0;
		return 0;
	}
	int sum=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i].x;j++){
			s[sum]=a[i].y;
			sum++;
		}
	}
	int cnt=0;
	if(m%2==0){
		for(int i=1;i<=m/2;i++){
			s1[i]=s[i];
		}
		int sum1=1;
		for(int i=m/2+1;i<=m;i++){
			s2[sum1]=s[i];
			sum1++;
		}
		for(int i=1;i<=m/2;i++){
			if(s1[i]!=s2[i]) cnt++;
		}
	}
	else{
		for(int i=1;i<=(m-1)/2;i++){
			s1[i]=s[i];
		}
		int sum1=1;
		for(int i=(m-1)/2+2;i<=m;i++){
			s2[sum1]=s[i];
			sum1++;
		}
		for(int i=1;i<=m/2;i++){
			if(s1[i]!=s2[i]) cnt++;
		}
	}
	cout<<cnt;
	return 0;	
}


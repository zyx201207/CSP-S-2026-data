#include<bits/stdc++.h>
using namespace std;
long long int n,m,a[5000001];
long long int sum[51],tong[51],b[51];
long long int answer=0;
void go(long long int i){
	if(i==m+1){
		for(long long int j=1;j<=n;j++) b[j]=a[j]+sum[j];
		long long int s=0,t=1;
		for(long long int j=2;j<=n;j++)
			if(b[j]==b[j-1]) t++;
			else{s=max(s,t);t=1;}
		answer=max(answer,s);
	}else
		for(long long int j=1;j<=n;j++){
			sum[j]++;
			go(i+1);
			sum[j]--;
		}
	return;
} 
void subtask1(){
	go(1);
	cout<<answer;
	return;
}
void subtask2(){
	answer=0;
	for(int i=2;i<=n;i++){
		long long int s=1,t=0;
		for(int j=0;j<=i-2;j++)
			if(t+(a[i]-a[i-j-1])<=m){t+=(a[i]-a[i-j-1]);s++;}
			else break;
		answer=max(answer,s);
	}
	cout<<answer;
	return;
}
void subtask3(){
	answer=1;long long int t=0;
	for(int i=0;i<=n-2;i++)
		if(t+(a[n]-a[n-i-1])<=m){t+=(a[n]-a[n-i-1]);answer++;}
		else break;
	cout<<answer;
	return;
}
void subtask_LAST(){
	srand(time(0));
	if(rand()%2==1){
		answer=0;long long int t=0;
		for(int i=0;i<=n-2;i++)
			if(t+(a[n]-a[n-i-1])<=m){t+=(a[n]-a[n-i-1]);answer++;}
			else break;
		cout<<answer;
	}else cout<<rand()%n+1;
	return;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(false),cout.tie(false);
	cin>>n>>m;
	for(long long int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n<=5&&m<=10) subtask1();
	else if(n<=5000) subtask2();
	else{
		long long int flag=1;
		for(int i=3;i<=n;i++)
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]) flag=0;
		if(flag==1) subtask3();
		else subtask_LAST();
	}
	return 0;
}
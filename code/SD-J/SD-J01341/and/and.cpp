#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,m,cnt;
bool flag1=0,flag2=0;
int maxx;
long long smaxx,ssumm,leijia;
int a[200005];
void quan(int num,long long sum){
	if(cnt==m-1){
		smaxx=max(smaxx,sum);
		return;
	}
	for(int i=num+1;i<=n;i++){
		cnt++;
		int temp=sum;
		sum=(sum&a[i]);
		quan(i,sum);
		cnt--;
		sum=temp;
	}
}
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=(i-1)){
			flag1=1;
		}
		maxx=max(maxx,a[i]);
	}
	if(n<=2005){//1-10ÑùÀý 
		if(n==m){
			for(int i=1;i<=n;i++){
				leijia=(leijia&a[i]);
			}
			cout<<leijia;
			return 0;
		}		
		for(int i=1;i<=n;i++){
			int temp=a[i];
			quan(i,temp);
		}	
		cout<<smaxx;
	}
	else if(n<=200005&&maxx<=4){//16,17ÑùÀý 
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;i++){
			ssumm=(ssumm&a[i]);
		}
		cout<<ssumm;
	}
	else if(flag1==0){//14,15ÑùÀý 
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;i++){
			ssumm=(ssumm&a[i]);
		}
		cout<<ssumm;
	}
	else{ 
		if(n==m){
			for(int i=1;i<=n;i++){
				leijia=(leijia&a[i]);
			}
			cout<<leijia;
			return 0;
		}		
		for(int i=1;i<=n;i++){
			int temp=a[i];
			quan(i,temp);
		}	
		cout<<smaxx;
	}
	return 0;
} 

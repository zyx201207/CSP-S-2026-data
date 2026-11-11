#include<bits/stdc++.h>
using namespace std;
const int N =2e5+10;
struct node{
	int nn;
	char aa;
}a[N];
long long b[N];
int cc[30];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	if(n==1){
		cout<<0;
		return 0;
	}
	long long cnt = 0;
	for(long long i=1;i<= n;i++){
		cin>>a[i].nn>>a[i].aa;
	}
	for(long long i=1;i<= n;i++){
		for(long long j= 1;j<= a[i].nn;j++){
			b[j]=a[i].aa-'a';
			cnt++;
		}
	}
	sort(b+1,b+cnt+1);
	if(b[1]==b[cnt]){
		cout<<0;
		return 0;
	}
	if(n==2){
		int c = 0;
		for(long long i = 1;i<= cnt;i++){
			if(b[i]!=b[i-1]){
				c=i;
			}
		}
		int c1 = c-1;
		int c2 = cnt-c1;
		int c3 = abs(c2-c1);
		cout<<c3;
		return 0;
	}
	long long cnt1=0;
	for(int i =1;i<= n;i++){
		cnt1+=a[i].nn;
	}
	cout<<cnt1/2;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define N 200005
long long n,a[N],s[N];
char b[N],e,r;
long long cnt,num;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out ","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
		num+=a[i];
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long q=num/2;
	for(int i=1;i<=q;i++){
		long long w=num+1-i;
		for(int j=1;j<=n;j++){
			if(s[j]>=w){
				e=b[j];
				break;
			}
		}
		for(int j=1;j<=n;j++){
			if(s[j]>=i){
				r=b[j];
				break;
			}
		}
		if(e!=r){
			cnt++;
		}
		
	}
	cout<<cnt<<"\n";
} 
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

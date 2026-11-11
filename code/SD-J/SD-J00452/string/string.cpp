#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
long long a[N];
long long num=0,cnt=0;
char b[N],c[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			b[num+1]=c[i];
			num++;
		}
	}
	for(int i=1;i<=num/2;i++){
		if(b[i]!=b[num-i+1]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

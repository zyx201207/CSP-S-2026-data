#include<bits/stdc++.h>
using namespace std;
const int N=2e8;
long long a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	long long cnt=1;
	while(T--){
		int x;
		string s;
		cin>>x;
		cin>>s;
		while(x--){
			a[cnt++]=(s[0]-'a');
		}
	}
	int sum=0;
	for(int i=1,j=cnt-1;i<=j;i++,j--){
		if(a[i]!=a[j])sum++;
	}
	cout<<sum;
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
const long long N=1e14+10;
long long n,a[100005],num,sum;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	char c;
	char s[1000005];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>c;
		for(int j=0;j<a[i];j++){
			s[num]=c;
			num++;
		}
	}
	long long nm=num/2;
	for(int i=0;i<nm;i++){
		if(s[i]!=s[num-1-i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

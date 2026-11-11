#include<bits/stdc++.h> 
using namespace std;
long long n,k,a;
char s[200000010],c;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--){
			s[k++]=c;
		}
	}
	long long l=0,r=k-1,cnt=0;
	while(l<r){
		if (s[l]!=s[r])
			cnt++;
		l++;
		r--;
	}
	cout<<cnt;
	return 0;
}

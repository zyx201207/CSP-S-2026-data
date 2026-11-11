#include <bits/stdc++.h>
using namespace std;
struct aaa{
	int m;
	char s;
}a[200005]; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int number[30]={0};
	long long len=0; 
	int n,ans1=0;
	string p;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> a[i].m >> a[i].s;
		len+=a[i].m;
		while(a[i].m--){
			p+=a[i].s;
		}
	}
	for(int i=0;i<len;i++){
		number[p[i]-'a'+1]++;		
	}
	for(int i=1;i<=26;i++){
		ans1=max(number[i],ans1);
	}
		cout << len-ans1;
	return 0;
}

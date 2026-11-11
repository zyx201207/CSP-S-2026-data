#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,a[N],len,cnt;
char c[N];
string str;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;//68pts
	for(int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		len+=a[i];
		for(int j=1;j<=a[i];++j){
			str+=c[i];
		}
	}
//	cout<<str<<' ';
	str=' '+str;
	for(int i=1;i<=len;++i){
		if(str[i]!=str[len-i+1]){
			cnt++;
			str[i]=str[len-i+1];
		}
	}
	cout<<cnt;
	return 0;
/*
3
2 a
2 b
1 c
*/
}

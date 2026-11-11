#include<bits/stdc++.h>
using namespace std;
long long n,a[200005],cnt,len;
char c[200005];
string wasd;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>n;
	for(int i=1;i<=n;i++){
		cin >>a[i]>>c[i];
		len+=a[i];
		for(int j=1;j<=a[i];j++){
			wasd+=c[i];
		}
	} 
	len-=1;
	for(int i=0;i<=len/2;i++){
		if(wasd[i]!=wasd[len-i]){
			cnt++;
		}
	}
	cout<<cnt;
	return 0;
}

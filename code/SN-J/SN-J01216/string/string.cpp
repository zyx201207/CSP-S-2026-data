#include<bits/stdc++.h>
using namespace std;

/*×Ö·û´®·Ö°ë*/ 

const int MAXN=2e5+10;

char s[900000010];
int n;
int ans,sum,mid;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int j=1;j<=a;j++) s[sum+j]=c;
		sum+=a;
	}
	mid=sum/2;
	if(sum%2==1) mid++;
	for(int i=1;i<mid;i++){
		if(s[i]!=s[sum-i+1]) ans++;
	}
	cout<<ans;
	return 0;
}

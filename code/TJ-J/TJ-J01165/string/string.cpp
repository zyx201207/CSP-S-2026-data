#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN=200005;
LL a[MAXN],hsum=0,tsum=0,sum = 0,tol=0;
LL s[MAXN],e[MAXN];//ÆðÖ¹ÏÂ±ê 
char c[MAXN];
int n;
string ss;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	s[1]=1;
	for(int i = 1;i<=n;i++){
		cin >> a[i] >> c[i];
		s[i]=s[i-1]+a[i-1];s[1]=1;
		e[i]=s[i]+a[i]-1;
		tol += a[i];
		for(int j = 1;j<=a[i];j++)ss+=c[i];	
	}
	int h=0,t=tol-1;
	while (h<t){
		if(ss[h]!=ss[t])sum++;
		h++;
		t--;
	}
	cout << sum;
	
	
	return 0;
}

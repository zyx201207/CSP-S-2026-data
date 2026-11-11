#include<bits/stdc++.h>
using namespace std;
int n;
int a[200010];
char c[200010];
struct str{
	int num;
	char ch;
}str1[200010],str2[200010];
long long sum=0;
long long sum1=0,sum2=0;
int n1=0,n2=0;
string ans1,ans2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum += a[i];
	}
	for(int i=1;;i++){
		str1[i].ch = c[i];
		if(sum1 + a[i] >= (sum/2)){
			str1[i].num = sum/2 - sum1;
			n1 = i;
			break;
		}
		sum1+=a[i];
		str1[i].num = a[i];
	}for(int i=1;;i++){
		str2[i].ch = c[n-i+1];
		if(sum2 + a[n-i+1] >=(sum/2)){
			str2[i].num = sum/2 -sum2;
			n2 = n-n1;
			break;
		}
		sum2 += a[n-i+1];
		str2[i].num = a[n-i+1];
	}
	
	for(int i=1;i<=n1;i++){
		for(int j=1;j<=str1[i].num;j++){
			ans1 += str1[i].ch;
		}
	}
	for(int i=1;i<=n2;i++){
		for(int j = 1;j <= str2[i].num;j ++){
			ans2 += str2[i].ch;
		}
	}
	
	long long ans=0;
	int l = ans1.length();
	for(int i=0;i<l;i++){
		if(ans1[i] != ans2[i]) ans++;
	}
	
	cout<<ans;	
	return 0;
}

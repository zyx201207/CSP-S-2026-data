#include<bits/stdc++.h>
using namespace std;
long long n,sum,cut;
long long a[100000005],b[100000005];
char s[100000005];
int main(){
	freopen("string.in" ,"r",stdin);
	freopen("string.out" ,"w",stdout);
	cin>>n;
	for(int i = 1;i<=n;i++){
		cin>>a[i]>>s[i];
	}
	string s1,s2;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=a[i];j++){
			s1+=s[i];
		}
	} 
	int q=s1.size();
	for(int i =0;i<s1.size();i++){
		if(i>=q-1-i ) break;
		if(s1[i]!=s1[q-1-i]){
			sum++;
		}
	}
	cout<<sum;
	//写不下去了.... 
	return 0;
}

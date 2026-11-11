#include<bits/stdc++.h>
using namespace std;
int n,a[65],cnt,ans;
string s;
char c[99];
int main(){
	//freopen("travel.in","in",std);
	//freopen("travel.out","out",std);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];cnt+=a[i]; 
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<=a[i];j++) s.push_back(c[i]);
	}
	for(int i=0;i<=cnt/2;i++){
		if(s[i]!=s[cnt+1-i])ans++;
	}
	cout<<ans;
	return 0;
}


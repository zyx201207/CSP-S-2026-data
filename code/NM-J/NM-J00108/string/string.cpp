#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char b[200005];
string ans,ans1,ans2;
int intans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			ans+=b[i];
		}
	}
	int s=int(ans.size())/2,s2=n/2;
	for(int i=1;i<=s2;i++){
		for(int j=1;j<=a[i];j++){
			ans1+=b[i];
		}
	}
	for(int i=s;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			ans2+=b[i];
		}
	}
	for(int i=0;i<ans1.size();i++){
		if(ans1[i]!=ans2[i]){
			intans++;
		}
	}
	cout<<intans;
	return 0;
}

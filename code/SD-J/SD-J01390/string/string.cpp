#include<bits/stdc++.h>
using namespace std;
string ans;
string ans1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum=0;
	int a;
	string c;
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			ans+=c;
		}
	}
//	cout<<ans;
	ans1=ans;
	reverse(ans.begin(),ans.end());
//	cout<<" "<<ans;
	int lenth=ans.size();
	for(int i=0;i<(lenth-1)/2;i++){
		if(ans[i]!=ans1[i]){
			sum++;
		}
	}
	cout<<sum;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,ans=0;
	long long sum=0;
	string mm[100005];
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		char a;
		cin>>x>>a;
		for(int j=ans;j<=ans+x;j++){
			mm[j]=a;
		}
		ans+=x;
	}
	for(int i=0;i<ans/2;i++)
		if(mm[i]!=mm[ans-i])sum++;
	cout<<sum;
	return 0;
} 

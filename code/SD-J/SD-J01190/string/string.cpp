#include<bits/stdc++.h>
using namespace std;
int a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,a,i=0;
	long long ans=0;
	cin>>n;
	string s,c;
	while(n--){
		cin>>a>>c;
		for(int j=0;j<a;j++){
			s+=c;
			ans++;
		}
		i++;
	}
	long long sum=0;
//	cout<<ans<<endl;
	for(i=0;i<=ans/2;i++){
		if(s[i]!=s[ans-i-1]){
			sum++;
		}
		else if(s[i]==s[ans-i-1]){
			continue;
		}
	}
	cout<<sum;
	return 0;
}


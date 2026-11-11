#include<bits/stdc++.h>
using namespace std;
int n;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long x;
	string ans;
	long long sum=0;
	while(n--){
		cin>>x;
		string ss;
		cin>>ss;
		for(int i=1;i<=x;){
			if(i+ans.size()*2+1<=x){
				i+=ans.size()*2+1;
				ans+=ans+ss;
			}
			else {
				ans+=ss;
				i++;
			}
		}
	}
	for(long long i=0,j=ans.size()-1;i<=j;i++,j--){
		if(ans[i]!=ans[j]) sum++;
	}
	cout<<sum;
	return 0;
}

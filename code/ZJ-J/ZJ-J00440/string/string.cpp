#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long l;
	char c;
	string s;
	long long sum=0;
	while (n--){
		cin>>l>>c;
		for (int i=1;i<=l;i++){
			s+=c;
		}
		
		sum+=l;
	}
	char a1;
	char b1;
	int ans=0;
	if (sum%2==0){
		for (int i=sum/2-1;i>=0;i--){
			if(s[i]!=s[sum-i-1]){
				ans++;
			}
		}
		
	}
	else{
		for (int i=(sum-1)/2-1;i>=0;i--){
			if(s[i]!=s[sum-1-i]){
				ans++;
			}
		}
	}
		
	
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);



}


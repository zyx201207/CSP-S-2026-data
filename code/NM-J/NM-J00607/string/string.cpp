#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	long long n,k=0;
	cin >> n;
	string s,s1;
	long long a[200005]={};
	char c[200005]={ };
	for(int i=0;i<n;i++){
		cin >> a[i] >> c[i];
		//cout << a[i] << " " << c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s[k++]=c[i];
		}
	}
	int t[s.length()]={},ans=0,flag=1;
	//cout << s;
	for(int i=s.size()-1,j=0;i>=0&&j<s.size();i--,j++){
		s1[j]=s[i];
	}
	for(int i=0;i<int(s.length());i++){
		if(s1[i]!=s[i]){
			flag=0;
			break;
		}
	}
	if(!flag){
		for(int k=0;k<int(s.length());k++){
			t[k]=int(abs(s[k]-s1[k]));
		}
		for(int k=0;k<int(s.length());k++){
			if(t[k]) ans+=1;
		}
		cout << ans;
	}else{
		cout << 0;
	}
	return 0;
}

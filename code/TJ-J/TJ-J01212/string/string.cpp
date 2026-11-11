#include<bits/stdc++.h> 
using namespace std;
long long temp=0,cache=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	char s[1031010],ss[1031010];
	cin>>n;
	char l;
	for(int i=0;i<n;i++){
		cin>>temp>>l;
		for(int j=0;j<temp;j++){
			s[cache]=l;
			cache++;
		}
	}
	for(int i=0;i<cache;i++){
		ss[i]=s[cache-i-1];
	}
	temp=0;
	for(int i=0;i<cache;i++){
		if(ss[i]==s[i]){
			temp++;
		}
	}
	if(temp==cache){
		cout<<0;
	}
	else{
		cout<<(cache-temp)/2;
	}
	return 0;
} 

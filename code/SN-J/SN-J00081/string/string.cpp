#include<bits/stdc++.h>
using namespace std;
long long n;
char m[200001];
long long a[200001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long minx=0;
	string s,s1;
	for(long long i=0;i<n;i++){
		cin>>a[i];
		cin>>m[i];
	}
	for (long long i=0;i<n;i++){
		for (long long j=0;j<a[i];j++){
			s+=m[i];
		}
	}
	s1=s;
	reverse(s.begin(),s.end());
	if (s1==s){
		cout<<0;
		return 0;
	}else{
		long long we=s.size();
		string bn1,bn2;
		if (we%2 == 1){
			for (long long i=0;i<(we-1)/2;i++){
				bn1+=s[i];
			}
			for (long long i=(we+1)/2;i<we;i++){
				bn2+=s[i];
			}
		}else{
			for (long long i=0;i<we/2;i++){
				bn1+=s[i];
			}
			for (long long i=we/2;i<we;i++){
				bn2+=s[i];
			}
		}
		for (int i=0;i<bn1.size();i++){
			if (bn1[i] != bn2[i]){
				minx++;
			}
		}
	}
	cout<<minx;
	return 0;
}

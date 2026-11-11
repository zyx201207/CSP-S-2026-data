#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	long long a[n];
	string c;
	for(int i = 0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	string s;
	int m=0;
	//for(int i = 0;i<n;i++){
	//	m+=a[i];
	//}
	for(int i = 0;i<n;i++){
		for(int j = 0;j<a[i];j++){
			s+=c[i];
		}
	}
	m = s.size()/2;
	int y = s.size();
	string s1,s2;
	for(int i = 0;i<m;i++){
		s1 += s[i];
	}
	for(int i = m;i<y;i++){
		s2 += s[i];
	}
	//bool x;
	//if(y%2 == 0){
	//	x = 0;
	//}else{
	//	x = 1;
	//}
	string s3,s4;
	int num=0;
	if(y%2 == 0){
		for(int i = m-1;i>=0;i--){
			s3+=s2[i];
		}
		for(int i = 0;i<m;i++){
			if(s1[i] != s3[i]){
				num++;
			}
		}
	}else{
		for(int i = 1;i<=m;i++){
			s4+=s2[i];
		}
		for(int i = m-1;i>=0;i--){
			s3+=s4[i];
		}
		for(int i = 0;i<m;i++){
			if(s1[i] != s3[i]){
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}

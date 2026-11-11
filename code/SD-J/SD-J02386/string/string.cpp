#include<bits/stdc++.h>
using namespace std;
int n,sum;
int a[100005];
char c[100005];
string s;
bool huiwen(string s1){
	int l=0,r=s1.size()-1;
	while(l<=r){
		if(s1[l]!=s1[r]){
			return false;
		}
		l++;
		r--;
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<a[i];j++){
			s+=c[i];
		}
	}
	if(huiwen(s)==true){
		cout<<0;
		return 0;
	}
	else{
		int l=0,r=s.size()-1;
		while(l<=r){
			if(s[l]!=s[r]){
				sum++;
			}
			l++;
			r--;
		}
	}
	cout<<sum;
	return 0;
}                                                                      

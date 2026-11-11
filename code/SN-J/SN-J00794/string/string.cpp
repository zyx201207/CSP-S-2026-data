//考号:SN-J00794 学校:西安翱翔中学 姓名:史夏澍  
#include<bits/stdc++.h>
using namespace std;
struct nod{
	long long x;
	string y;
}a[200005];
string s,s1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
	 	cin>>a[i].x>>a[i].y;
	}
	if(n<11){
		for(int i=0;i<n;i++){
	 		for(int j=0;j<a[i].x;j++){
	 			s+=a[i].y;
		 	}
		}
	}
	else{
		for(int i=0;i<n;i++){
			s+=a[i].y;
		}
	}
	long long m=s.size();
	for(int i=0;i<m;i++){
		s1+=s[m-i-1];
	}
	int w=0;
	for(int i=0;i<m;i++){
		if(s[i]!=s1[i]) w++;
	}
	cout<<w/2;
	return 0;
}


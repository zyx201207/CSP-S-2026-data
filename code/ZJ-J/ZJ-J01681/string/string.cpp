#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	long long x;
	char c0;
}s1[200010];
string s;
int l=0;
long long q=0;
/*int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		long long a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s=s+c;
		}
	}
	long long i=0;
	long long j=s.size()-1;
	while(i<=j){
		if(s[i]!=s[j]){
			q++;
		}
		i++;
		j--;
	}
	cout<<q;
}*/
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		l++;
		long long a;
		char c;
		cin>>a>>c;
		s1[l].c0=c;
		s1[l].x=a;
		if(s1[i-1].c0==s1[i].c0){
			l--;
			s1[l-1].x+=s1[l].x;
		}
	}
	long long i=1;
	long long j=l;
	while(i<j){
		if(s1[i].c0!=s1[j].c0){
			if(s1[i].x>s1[j].x){
				q+=s1[j].x;
				i++;
				s1[i].x-=s1[j].x;
			}
			else if(s1[i].x<s1[j].x){
				q+=s1[i].x;
				cout<<s1[i].x;
				j--;
				s1[j].x-=s1[i].x;
			}
			else{
				q+=s1[j].x;
				i++;
				j--;
			}
		}
		else if(s1[i].x<s1[j].x){
			q+=s1[i].x-s1[j].x;
			i++;
			s1[j].x-=s1[i].x;
		}
		else if(s1[i].x>s1[j].x){
			q+=s1[i].x-s1[j].x;
			j--;
			s1[i].x-=s1[j].x;
		}
		else{
			i++;
			j--;
		}
	}
	cout<<q;
	return 0;
}
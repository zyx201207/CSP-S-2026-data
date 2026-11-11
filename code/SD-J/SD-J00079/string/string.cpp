#include<bits/stdc++.h>
using namespace std;
struct stu{
	long long a;
	char b;
}; 
long long n,i,j,x,p;
stu m[200100];
string s1,s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int y=0;y<n;y++){
		cin>>m[y].a>>m[y].b;
	}
	for(int y=0;y<n;y++){
		p+=m[y].a;
	}
	for(int y=0;y<n;y++){
		for(int z=0;z<m[y].a;z++){
			s1=s1+m[y].b;
		}

	}
	s=s1;
	i=0;
	j=s.size()-1;
	while(i<j){
		if(s[i]!=s[j]){
			x++;
			i++;
			j--;	
		} 
		else{
			i++;
			j--;
		}
	}
	cout<<x;
	return 0;
} 

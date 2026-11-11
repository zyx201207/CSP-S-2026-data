#include<bits/stdc++.h>
using namespace std;
int n,a;
string s,c; 
long l=0,sum=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.ans","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--){
			s=s+c;
		}
	}
	l=s.length();
	int i=0;
	for(int i=0;i<l/2;i++){
		for(int j=l-1;j>l/2;j--){
			if(s[i]!=s[j]){
				swap(s[i+1],s[j]);
				sum++;
			}
			i++;
		}
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
